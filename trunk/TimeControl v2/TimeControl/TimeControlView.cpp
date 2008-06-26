// TimeControlView.cpp : implementation of the CTimeControlView class
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgAdding.h"
#include "Task.h"
#include "DlgError.h"
#include "DlgSure.h"
#include "DlgCorrect.h"
#include "DlgAllTasks.h"

#include "TimeControlDoc.h"
#include "TimeControlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeControlView

IMPLEMENT_DYNCREATE(CTimeControlView, CFormView)

BEGIN_MESSAGE_MAP(CTimeControlView, CFormView)
	//{{AFX_MSG_MAP(CTimeControlView)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_COMMAND(ID_add_task, Onaddtask)
	ON_WM_TIMER()
	ON_COMMAND(ID_Stop_Time, OnStopTime)
	ON_COMMAND(ID_Delete, OnDelete)
	ON_COMMAND(ID_correct, Oncorrect)
	ON_COMMAND(ID_ARCHIVE, OnArchive)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_SHOW, OnShowAll)
	ON_COMMAND(ID_ViewAllTime, OnViewAllTime)
	ON_UPDATE_COMMAND_UI(ID_ViewAllTime, OnUpdateViewAllTime)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeControlView construction/destruction

CTimeControlView::CTimeControlView()
	: CFormView(CTimeControlView::IDD)
{
	//{{AFX_DATA_INIT(CTimeControlView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	IsColumnes = FALSE;
}

CTimeControlView::~CTimeControlView()
{
}

void CTimeControlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimeControlView)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BOOL CTimeControlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTimeControlView::OnInitialUpdate()
{
	NowActiveProject = -1;
	OnStopTime();
	
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_list.DeleteAllItems();
	GetDocument()->ActiveTasks.RemoveAll();
	if(!IsColumnes)
	{
		m_list.InsertColumn(0,"название задачи", LVCFMT_LEFT, 200);
		m_list.InsertColumn(1,"тип задачи",LVCFMT_LEFT, 70);
		if(!GetDocument()->IsAllTimeVisible)
		{
			m_list.InsertColumn(2,"всё затраченное время", LVCFMT_RIGHT, 0);
			m_list.InsertColumn(3,"cегодня затраченное время", LVCFMT_RIGHT, 160);
		}
		else
		{
			m_list.InsertColumn(2,"всё затраченное время", LVCFMT_RIGHT, 160);
			m_list.InsertColumn(3,"cегодня затраченное время", LVCFMT_RIGHT, 0);
		}
	}
	IsColumnes = TRUE;
	CTask* NowTask; 
	//what day today?
 	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	GetDocument()->DayToday = timeinfo->tm_yday;

	POSITION pos = GetDocument()->AllTasks.GetHeadPosition();
	while(pos!= NULL)
	{
		// my actions
		NowTask = (CTask*) GetDocument()->AllTasks.GetNext(pos);
		//my actions with NowTask if it is visible
		if(NowTask->IsTaskVisible())
		{
			NowTask->TestNewDay(timeinfo);
			int m_item = m_list.GetItemCount();
			m_list.InsertItem(m_item, NowTask->GetName());
			m_list.SetItemText(m_item, 1, Type(NowTask->GetType()));
			m_list.SetItemText(m_item, 2, NowTask->GetTimeSpent());
			m_list.SetItemText(m_item, 3, NowTask->GetTimeSpentToday());

			TRACE("%d",GetDocument()->ActiveTasks.GetCount());

			GetDocument()->ActiveTasks.AddTail(NowTask);
		}

	}

	KillTimer(2);
	SetTimer(2, 60000, NULL);
}
//my functions
CString CTimeControlView::Archive(bool IsInArchive)
{
	if(IsInArchive)
		return("Задача скрыта");
	return("Задача активна");
}
CString CTimeControlView::Type(int int_Type)
{

	if(int_Type == 0)
		return("работа");

	if(int_Type == 1)
		return("отдых");

	return("error");
}


void CTimeControlView::FindActive()
{
	NowActiveProject = -1;
	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		if( m_list.GetItemState( k, LVIS_SELECTED) == LVIS_SELECTED )
			NowActiveProject = k;
	}

	if(NowActiveProject == -1)
		return;
	
	p_NowActiveProject = GetDocument()->ActiveTasks.FindIndex(NowActiveProject);
}

void CTimeControlView::StartTime()
{
	
	OnStopTime();
	FindActive();
	if(NowActiveProject == -1)
		return;
	
	CTask* ActiveTask;
	ActiveTask = (CTask*)GetDocument()->ActiveTasks.GetAt(p_NowActiveProject);
	ActiveTask->StartTime();
	
	KillTimer(1); //kill old timer
	SetTimer(1,500,NULL);//and start new
	GetDocument()->SetModifiedFlag();
}

void CTimeControlView::TestDayToday()
{
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	
	if(GetDocument()->DayToday != timeinfo->tm_yday)
	{
		NewDay();
	}

}
void CTimeControlView::NewDay()
{
	bool WasStopped = (NowActiveProject != -1);
	OnStopTime();
	
	//start finding today day
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	// stop finding today day

	GetDocument()->DayToday = timeinfo->tm_yday;
	
	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		m_list.SetItemText(k, 3,"0:00:00");
	}

	POSITION pos = GetDocument()->ActiveTasks.GetHeadPosition();
	CTask* NowTask;
	while(pos!= NULL)
	{
		// my actions
		NowTask = (CTask*) GetDocument()->ActiveTasks.GetNext(pos);
		NowTask->NewDay();
	}
	
	if(WasStopped)
		StartTime();
}



/////////////////////////////////////////////////////////////////////////////
// CTimeControlView printing

BOOL CTimeControlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	pInfo->SetMaxPage((m_list.GetItemCount()+CTimeControlDoc::nLinesPerPage-1)/CTimeControlDoc::nLinesPerPage );
	return DoPreparePrinting(pInfo);
}

void CTimeControlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTimeControlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTimeControlView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add customized printing code here
	int i, nStart, nEnd, nHeight;
	CString str;
	CPoint point(720, -1440);
	CFont font;
	TEXTMETRIC tm;
	pDC->SetMapMode(MM_TWIPS);

	m_nPage = pInfo->m_nCurPage;
	nStart = (m_nPage - 1) * CTimeControlDoc::nLinesPerPage;
	nEnd = nStart + CTimeControlDoc::nLinesPerPage;

	//font.CreateFont(-280, 0, 0, 0, 400, FALSE, FALSE, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_MODERN, "Arial");
	
	//CFont* pOldFont = (CFont*)(pDC->SelectObject(&font));
	PrintPageHeader(pDC);
	pDC->GetTextMetrics(&tm);
	nHeight = tm.tmHeight +tm.tmExternalLeading;

	for(i = nStart; i<nEnd ; i++)
	{
		if(i>m_list.GetItemCount())
			break;
		str.Format(_T("%-40s%-15s%15s"), m_list.GetItemText(i,0), m_list.GetItemText(i,1), m_list.GetItemText(i,2));
		point.y -= nHeight;
		pDC->TextOut(point.x, point.y, str);
	}
	//pDC->SelectObject(pOldFont);
	PrintPageFooter(pDC);
}



void CTimeControlView::PrintPageHeader(CDC *pDC)
{
	CString str;
	
	CPoint point(0,0);
	pDC->TextOut(point.x, point.y, "Отчёт по заданиям");
	point+= CSize(720,-720);
	str.Format(_T("%-40.40s%-15.15s%15.15s"), "название проекта", "тип проекта", "время(всего)");
	pDC->TextOut(point.x, point.y, str);
}

void CTimeControlView::PrintPageFooter(CDC *pDC)
{
	CString str;

	CPoint point(100, -14400);
	str.Format("Document %s", (LPCSTR) GetDocument()->GetTitle());
	pDC->TextOut(point.x, point.y, str);
	str.Format("Page %d", m_nPage);
	CSize size = pDC->GetTextExtent(str);
	point.x += 11000 - size.cx;
	pDC->TextOut(point.x, point.y, str);
}
/////////////////////////////////////////////////////////////////////////////
// CTimeControlView diagnostics

#ifdef _DEBUG
void CTimeControlView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTimeControlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTimeControlDoc* CTimeControlView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimeControlDoc)));
	return (CTimeControlDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTimeControlView message handlers

void CTimeControlView::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	
	StartTime();

	*pResult = 0;
}



void CTimeControlView::Onaddtask() 
{
	// TODO: Add your command handler code here
	CDlgAdding dlg;
	dlg.m_Type = 0;
	OnStopTime();
	int Result = dlg.DoModal();
	

	
	if(Result == IDCANCEL)
		return;
	
	
	//bad case - no name
	dlg.m_Name.TrimLeft(_T(" "));
	if(!strlen(dlg.m_Name))
	{
		CDlgError Error;
		Error.DoModal();
		Result = dlg.DoModal();
		if(Result != IDOK)
			return;
		dlg.m_Name.TrimLeft(_T(" "));
		if(!strlen(dlg.m_Name))
			return;
	}
	dlg.m_Name.TrimRight(_T(" "));


	//Taking information , new object

	CTask* NewTask;
	NewTask = new CTask( dlg.m_Type, dlg.m_Name);

	GetDocument()->ActiveTasks.AddTail(NewTask);
	GetDocument()->AllTasks.AddTail(NewTask);
	
	int l_item = m_list.InsertItem(m_list.GetItemCount(), dlg.m_Name);
	m_list.SetItemText(l_item, 1, Type(dlg.m_Type));
	m_list.SetItemText(l_item, 2, "0:00:00");
	m_list.SetItemText(l_item, 3, "0:00:00");
	m_list.SetItemState(l_item,  LVIS_FOCUSED | LVIS_SELECTED , LVIS_FOCUSED | LVIS_SELECTED);
	StartTime();

	
	
}


void CTimeControlView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		
	if(nIDEvent == 1)
	{
		CTask* ActiveTask;
		ActiveTask = (CTask*)GetDocument()->ActiveTasks.GetAt(p_NowActiveProject);
		
			
		
		m_list.SetItemText(NowActiveProject, 2, ActiveTask->TimeUpdate());
		m_list.SetItemText(NowActiveProject, 3, ActiveTask->GetTimeSpentToday());
		m_list.SetItemState( NowActiveProject , LVIS_FOCUSED | LVIS_SELECTED , LVIS_FOCUSED | LVIS_SELECTED );
		GetDocument()->SetModifiedFlag();
	}

	if(nIDEvent == 2)
	{
		TestDayToday();
		
	}

	CFormView::OnTimer(nIDEvent);

} 

void CTimeControlView::OnStopTime() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
	if(NowActiveProject == -1)
		return;
	
	CTask* ActiveTask;
	ActiveTask = (CTask*)GetDocument()->ActiveTasks.GetAt(p_NowActiveProject);
	ActiveTask->StopTime();
	NowActiveProject = - 1;

	for(int i = m_list.GetItemCount() - 1; i>=0; i--)
	{
		m_list.SetItemState( i , 0 , 0 );
	}
}

void CTimeControlView::OnDelete() 
{
	// TODO: Add your command handler code here
	OnStopTime();


	FindActive();
	if(NowActiveProject == -1)
		return;

	CDlgSure dlg;
	int sure = dlg.DoModal();

	if(sure != IDOK)
		return;


	m_list.DeleteItem(NowActiveProject);
	
	//deleting from document
	CTask* ActiveTask;
	ActiveTask = (CTask*)GetDocument()->ActiveTasks.GetAt(p_NowActiveProject);
	
	GetDocument()->ActiveTasks.RemoveAt(p_NowActiveProject);

	POSITION pos = GetDocument()->AllTasks.Find(ActiveTask);
	GetDocument()->AllTasks.RemoveAt(pos);
	GetDocument()->SetModifiedFlag();
	NowActiveProject = -1; // no active projects
}

void CTimeControlView::Oncorrect() 
{
	// TODO: Add your command handler code here
	OnStopTime();
	
	FindActive();
	if(NowActiveProject==-1)
		return;
	
	CTask* ActiveTask;
	ActiveTask = (CTask*)GetDocument()->ActiveTasks.GetAt(p_NowActiveProject);
	
	CDlgCorrect dlg;
	//taking parametres
	dlg.m_Name = ActiveTask->GetName();
	dlg.m_Type = ActiveTask->GetType();
	dlg.m_IsNegative = 0;
	dlg.m_Hours = "0";
	dlg.m_Minutes = "00";
	dlg.m_Seconds = "00";

	int Result;
	Result = dlg.DoModal();
	
	if(Result!=IDOK)
		return;
	
	//bad case - no name
	dlg.m_Name.TrimLeft(_T(" "));
	if(!strlen(dlg.m_Name))
	{
		CDlgError Error;
		Error.DoModal();
		Result = dlg.DoModal();
		if(Result!=IDOK)
			return;
		dlg.m_Name.TrimLeft(_T(" "));
		if(!strlen(dlg.m_Name))
			return;
		
	}
	dlg.m_Name.TrimRight(_T(" "));


	CString NowTime = ActiveTask->Correct(dlg.m_Name, dlg.m_IsNegative, dlg.m_NotToday, dlg.m_Hours, dlg.m_Minutes, dlg.m_Seconds);
	m_list.SetItemText(NowActiveProject, 2,NowTime); 
	m_list.SetItemText(NowActiveProject, 3,ActiveTask->GetTimeSpentToday());
	m_list.SetItemText(NowActiveProject, 0,dlg.m_Name);
	GetDocument()->SetModifiedFlag();
	NowActiveProject = -1;
	StartTime();
}




void CTimeControlView::OnArchive() 
{
	// TODO: Add your command handler code here
	OnStopTime();
	FindActive();

	if(NowActiveProject==-1)
		return;

	CTask* task;
	task = (CTask*) GetDocument()->ActiveTasks.GetAt(p_NowActiveProject);
	task->Archive();
	GetDocument()->ActiveTasks.RemoveAt(p_NowActiveProject);
	m_list.DeleteItem(NowActiveProject);
	
	GetDocument()->SetModifiedFlag();
	NowActiveProject = -1;
}

void CTimeControlView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenu(IDR_CONTEXTMENU);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON, point.x, point.y, this);

}

void CTimeControlView::OnShowAll() 
{
	// TODO: Add your command handler code here
	OnStopTime();
	
	CDlgAllTasks dlg;
	//giving list of objects from document to dlg
	dlg.m_ObList = &GetDocument()->AllTasks;

	dlg.DoModal();
	
	OnInitialUpdate();


}

void CTimeControlView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
}

void CTimeControlView::OnViewAllTime() 
{
	// TODO: Add your command handler code here
	GetDocument()->IsAllTimeVisible = !GetDocument()->IsAllTimeVisible;
	if(GetDocument()->IsAllTimeVisible)
	{
		m_list.SetColumnWidth(2, 160);
		m_list.SetColumnWidth(3, 0);
	}
	else
	{
		m_list.SetColumnWidth(2, 0);
		m_list.SetColumnWidth(3, 160);
	}
}

void CTimeControlView::OnUpdateViewAllTime(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(GetDocument()->IsAllTimeVisible);
	pCmdUI->ContinueRouting();
}
