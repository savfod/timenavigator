// timecontrolView.cpp : implementation of the CTimecontrolView class
//

#include "stdafx.h"
#include "timecontrol.h"
#include "AddingDialog.h"
#include "SureDlg.h"
#include "CorrectDlg.h"
#include "NewList.h"

#include "timecontrolDoc.h"
#include "timecontrolView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolView

IMPLEMENT_DYNCREATE(CTimecontrolView, CFormView)

BEGIN_MESSAGE_MAP(CTimecontrolView, CFormView)
	//{{AFX_MSG_MAP(CTimecontrolView)
	ON_COMMAND(ID_add_task, Onaddtask)
	ON_WM_TIMER()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_COMMAND(ID_Stop_Time, OnStopTime)
	ON_COMMAND(ID_Delete, OnDelete)
	ON_COMMAND(ID_correct, Oncorrect)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE_AS, OnFileSaveAs)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_MENUITEM32785, OnMenuitem32785)
	ON_WM_CONTEXTMENU()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolView construction/destruction

CTimecontrolView::CTimecontrolView()
	: CFormView(CTimecontrolView::IDD)
{
	//{{AFX_DATA_INIT(CTimecontrolView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CTimecontrolView::~CTimecontrolView()
{
}

void CTimecontrolView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTimecontrolView)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}

BOOL CTimecontrolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CTimecontrolView::OnInitialUpdate()
{
	
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	m_list.InsertColumn(0,"название проекта", LVCFMT_LEFT, 300);
	m_list.InsertColumn(1,"затраченное время", LVCFMT_RIGHT, 130);
	
}

int CTimecontrolView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	CTimecontrolView::wasSaved = FALSE;
	strcpy(CTimecontrolView::m_StandartSavePlace,"TimeControl.tc");

	return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolView printing

BOOL CTimecontrolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTimecontrolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTimecontrolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTimecontrolView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
	CPaintDC dc(this);
	OnPrepareDC(&dc);
	OnDraw(&dc);
}

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolView diagnostics

#ifdef _DEBUG
void CTimecontrolView::AssertValid() const
{
	CFormView::AssertValid();
}

void CTimecontrolView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CTimecontrolDoc* CTimecontrolView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimecontrolDoc)));
	return (CTimecontrolDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolView message handlers



void CTimecontrolView::Onaddtask() 
{
	// TODO: Add your command handler code here
	CAddingDialog AddingDialog;
	AddingDialog.DoModal();
	
	m_DataCode = AddingDialog.m_strProjectName;
	m_DataCode.TrimLeft(_T(" "));
	m_Time = "0:00:00";
	
		
	if(!strlen(m_DataCode))
	return;
	
	
	g_img_column_data = 100;
	int l_id;
	l_id = 5;
	int l_item = m_list.InsertItem(m_list.GetItemCount() , m_DataCode , g_img_column_data );
	m_list.SetItemData( l_item , ( DWORD )l_id );
	m_list.SetItemText(l_item, 1, m_Time);
	m_list.SetItemState( l_item, LVIS_FOCUSED, LVIS_FOCUSED | LVIS_SELECTED );
	
	TimeCounter.newNowProject(l_item, m_list.GetItemText(l_item, 1));
	KillTimer(1);
	
	SetTimer(1,500,NULL);
	
}






void CTimecontrolView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		CString newTime = TimeCounter.TimeUpdate();
	
		int l_item = TimeCounter.TakeIndex();	
		
		m_list.SetItemText(l_item, 1, newTime);
		m_list.SetItemState( l_item , LVIS_FOCUSED | LVIS_SELECTED , LVIS_FOCUSED | LVIS_SELECTED );
	}

	if(nIDEvent == 2)
	{
		CTimecontrolView::OnFileSave();
	}
	
	CFormView::OnTimer(nIDEvent);
}

void CTimecontrolView::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	

	
	int i=-1;
	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		if( m_list.GetItemState( k, LVIS_SELECTED) == LVIS_SELECTED )
			i = k;
	}
		//если же действительно выделен, надо начать считать время...
	
	if(i==-1)
		return;

	TimeCounter.newNowProject(i, m_list.GetItemText(i, 1));
	KillTimer(1);
	
	SetTimer(1,500,NULL);


	*pResult = 0;
}

void CTimecontrolView::OnStopTime() 
{
	// TODO: Add your command handler code here
	KillTimer(1);
}



void CTimecontrolView::OnDelete() 
{
	// TODO: Add your command handler code here
	CTimecontrolView::OnStopTime();




	CSureDlg dlg;
	int sure = dlg.DoModal();

	if(sure == 2)
		return;

	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		if( m_list.GetItemState( k, LVIS_SELECTED) == LVIS_SELECTED )
		{
			m_list.DeleteItem(k);
			return;
		}
	}
}

void CTimecontrolView::Oncorrect() 
{
	// TODO: Add your command handler code here
	
	//learn index
	int index = -1;
	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		if( m_list.GetItemState( k, LVIS_SELECTED) == LVIS_SELECTED )
			index = k;
	}
	

	if(index == -1)
		return;


	//stop time

	CTimecontrolView::OnStopTime();
	
	//call dialog
	CString time = m_list.GetItemText(index, 1);

	CCorrectDlg dlg;
	
	
	dlg.m_seconds = time.Right(2);
	

	time.Delete(time.GetLength() - 3, 3); // ':xx'
	dlg.m_minutes = time.Right(2);

	time.Delete(time.GetLength() - 3, 3); // ':xx'
	dlg.m_hours = time;

	dlg.m_project = m_list.GetItemText(index, 0);

	

	int sure = dlg.DoModal();	
	if(sure!=1)
		return;

	//else update time (and name)

	CString name = dlg.m_project;
	name.TrimLeft(_T(" "));
	
	if(name.GetLength())
	m_list.SetItemText(index,0, name);

	
	CString hours = dlg.m_hours.SpanIncluding("0123456789");
	
	
	CString minutes = dlg.m_minutes.SpanIncluding("0123456789");
	if(minutes.GetLength() != 2)  //we need 2 haracters
	{
		minutes = '0' + minutes;
	}
	if(minutes.GetLength() != 2)
	{
		minutes = '0' + minutes;
	}


	CString seconds = dlg.m_seconds.SpanIncluding("0123456789");
	if(seconds.GetLength() != 2)  //we need 2 haracters
	{
		seconds = '0' + seconds;
	}
	if(seconds.GetLength() != 2)
	{
		seconds = '0' + seconds;
	}

	time = hours + ':' + minutes + ':' + seconds;

	m_list.SetItemText(index,1, time);


}


void CTimecontrolView::OnFileOpen() 
{
	// TODO: Add your command handler code here
	CFileDialog m_Open(TRUE, "tc", "TimeControl.tc");
	int Result = m_Open.DoModal();
	
	if(Result!=IDOK)
		return;


	CFile file;
	file.Open(m_Open.GetPathName(),CFile::modeRead);

	//deleting
	m_list.DeleteAllItems();

	//
	
	CTimecontrolView::wasSaved = FALSE;
	KillTimer(2);
	//the most intresting part - reading
	
	

	char buffer[50];
	int i = 0;
	int WasRead = 1;
	CString read;
	

	
	
	
	while(WasRead)
	{
		//reading
		for(i = 0, WasRead = 1; (i<49) && (buffer[i-1] != char(164)) && WasRead; i++) 
		{
			WasRead = file.Read(buffer + i,1);
		}
		
		
		//writing to list

		if(WasRead) //for case EOF
		{
			buffer[i-1] = 0;
			read.Empty();
			read.Format(_T("%s"), buffer);
			m_list.InsertItem(0, read);
		}


		//reading
		
		for(i = 0, WasRead = 1; (i<49) && (buffer[i-1] != char(164)) && WasRead; i++) 
		{
			WasRead = file.Read(buffer + i,1);
		}
		
		
		//writing to list
		
		if(WasRead) //for case EOF
		{
			buffer[i-1] = 0;
			read.Empty();
			read.Format(_T("%s"), buffer);
			m_list.SetItemText(0,1,read);
	
		}
	}
	lstrcpy(CTimecontrolView::m_StandartSavePlace,(m_Open.GetPathName()));
	CTimecontrolView::wasSaved = TRUE;
		
	SetTimer(2,20000,NULL);

}

void CTimecontrolView::OnFileSaveAs() 
{
	// TODO: Add your command handler code here
	CFileDialog m_Open(FALSE, "tc", "TimeControl.tc");
	int Result = m_Open.DoModal();

	if(Result != IDOK)
	return;


	lstrcpy(CTimecontrolView::m_StandartSavePlace,(m_Open.GetPathName()));
	TRACE(m_Open.GetPathName());
	CTimecontrolView::wasSaved = TRUE;
	CTimecontrolView::OnFileSave();

	SetTimer(2,20000,NULL);
	
}

void CTimecontrolView::OnFileSave() 
{
	// TODO: Add your command handler code here
	
	if(!wasSaved)
	CTimecontrolView::OnFileSaveAs();
	
	CFile  file;
	file.Open(CTimecontrolView::m_StandartSavePlace, CFile::modeCreate);
	file.Close();
	file.Open(CTimecontrolView::m_StandartSavePlace, CFile::modeWrite);
	
	CString buff;
	int length;

	void* buffer;
	//int ItemCount = m_list.GetItemCount();
	for( int k = m_list.GetItemCount() - 1 ; k >= 0; k-- )
	{	
		buff = m_list.GetItemText(k,0) +  char(164);
		length = buff.GetLength()  ;
		buffer = buff.GetBuffer(length);
		file.Write(buffer, length);
		
		buff = m_list.GetItemText(k,1) +  char(164);
		length = buff.GetLength() ;
		buffer = buff.GetBuffer(length);
		file.Write(buffer, length);

	
	}
	
	
	
}

void CTimecontrolView::OnFileNew() 
{
	// TODO: Add your command handler code here
	NewList dlg;
	int Result = dlg.DoModal();
	
	if(Result != IDOK)
		return;

	KillTimer(2);
	m_list.DeleteAllItems();
	
	wasSaved = FALSE;

}

void CTimecontrolView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	
}

void CTimecontrolView::OnMenuitem32785() 
{
	// TODO: Add your command handler code here
	int i=-1;
	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		if( m_list.GetItemState( k, LVIS_SELECTED) == LVIS_SELECTED )
			i = k;
	}
		//если же действительно выделен, надо начать считать время...
	
	if(i==-1)
		return;

	TimeCounter.newNowProject(i, m_list.GetItemText(i, 1));
	KillTimer(1);
	
	SetTimer(1,500,NULL);


}

void CTimecontrolView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	CTimecontrolView::OnStopTime();
	// TODO: Add your message handler code here
	CMenu menu;
	menu.LoadMenu(IDR_ContextMenu);
	menu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
}


