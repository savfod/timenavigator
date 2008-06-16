// TimeControlView.cpp : implementation of the CTimeControlView class
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgAdding.h"
#include "Task.h"
#include "DlgError.h"
#include "DlgSure.h"
#include "DlgCorrect.h"

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
	if(!IsColumnes)
	{
		m_list.InsertColumn(0,"название задачи", LVCFMT_LEFT, 200);
		m_list.InsertColumn(1,"тип задачи",LVCFMT_LEFT, 70);
		m_list.InsertColumn(2,"затраченное время", LVCFMT_RIGHT, 121);
	}
	IsColumnes = TRUE;
	CTask* NowTask; 
	POSITION pos = GetDocument()->AllTasks.GetHeadPosition();
	while(pos!= NULL)
	{
		// my actions
		NowTask = (CTask*) GetDocument()->AllTasks.GetNext(pos);
		//my actions with NowTask if it is visible
		if(NowTask->IsTaskVisible())
		{
			int m_item = m_list.GetItemCount();
			m_list.InsertItem(m_item, NowTask->GetName());
			m_list.SetItemText(m_item, 1, Type(NowTask->GetType()));
			m_list.SetItemText(m_item, 2, NowTask->GetTimeSpent());
			
			TRACE("%d",GetDocument()->ActiveTasks.GetCount());

			GetDocument()->ActiveTasks.AddTail(NowTask);
		}

	}
}
//my functions
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





/////////////////////////////////////////////////////////////////////////////
// CTimeControlView printing

BOOL CTimeControlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
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

void CTimeControlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
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
	int Result = dlg.DoModal();
	

	
	if(Result == IDCANCEL)
		return;
	
	
	//bad case - no name
	dlg.m_Name.TrimLeft(_T(" "));
	if(!strlen(dlg.m_Name))
	{
		CDlgError Error;
		Error.DoModal();
		return;
	}


	//Taking information , new object

	CTask* NewTask;
	NewTask = new CTask( dlg.m_Type, dlg.m_Name);

	GetDocument()->ActiveTasks.AddTail(NewTask);
	GetDocument()->AllTasks.AddTail(NewTask);
	
	int l_item = m_list.InsertItem(m_list.GetItemCount(), dlg.m_Name);
	m_list.SetItemText(l_item, 1, Type(dlg.m_Type));
	m_list.SetItemText(l_item, 2, "0:00:00");
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
		m_list.SetItemState( NowActiveProject , LVIS_FOCUSED | LVIS_SELECTED , LVIS_FOCUSED | LVIS_SELECTED );
		GetDocument()->SetModifiedFlag();
	}

	/*if(nIDEvent == 2)
	{
		CTimecontrolView::OnFileSave();
	}*/

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

	CString NowTime = ActiveTask->Correct(dlg.m_Name, (bool)dlg.m_IsNegative, dlg.m_Hours, dlg.m_Minutes, dlg.m_Seconds);
	m_list.SetItemText(NowActiveProject, 2,NowTime); 
	GetDocument()->SetModifiedFlag();
	//NowActiveProject = -1;//лишнее
	StartTime();
}



