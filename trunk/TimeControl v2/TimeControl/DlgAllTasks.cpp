// DlgAllTasks.cpp : implementation file
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgAllTasks.h"
#include "Task.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAllTasks dialog


CDlgAllTasks::CDlgAllTasks(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAllTasks::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAllTasks)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgAllTasks::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAllTasks)
	DDX_Control(pDX, IDC_LIST1, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAllTasks, CDialog)
	//{{AFX_MSG_MAP(CDlgAllTasks)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()




//my functions
CString CDlgAllTasks::IsVisible(bool IsVis)
{
	if(IsVis)
		return("активна");
	return("скрыта");
}

CString CDlgAllTasks::Type(int type)
{
	if(type == 0)
		return("работа");

	if(type == 1)
		return("отдых");

	return("error");
}
int CDlgAllTasks::FindActive()
{
	for( int k = m_list.GetItemCount() - 1; k >= 0; k-- )
	{	
		if( m_list.GetItemState( k, LVIS_SELECTED) == LVIS_SELECTED )
			return(k);
	}
	return(-1);
}
CString CDlgAllTasks::ChangeActive(CString now)
{
	if(now == "активна")
		return("скрыта");
	if(now == "скрыта")
		return("активна");
	return("error");
}
/////////////////////////////////////////////////////////////////////////////
// CDlgAllTasks message handlers

void CDlgAllTasks::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	int Active = FindActive();
	if(Active == -1)
		return;
	m_list.SetItemData(Active, !(m_list.GetItemData(Active)));
	m_list.SetItemText(Active, 3, ChangeActive(m_list.GetItemText(Active,3)));

	*pResult = 0;
}

BOOL CDlgAllTasks::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	
	m_list.InsertColumn(0,"название задачи", LVCFMT_LEFT, 200);
	m_list.InsertColumn(1,"тип задачи",LVCFMT_LEFT, 70);
	m_list.InsertColumn(2,"затраченное время", LVCFMT_LEFT, 121);
	m_list.InsertColumn(3,"статус", LVCFMT_RIGHT, 150);
	
	POSITION pos = m_ObList->GetHeadPosition();
	CTask* NowTask;
	int l_item;
	while(pos != NULL)
	{
		NowTask = (CTask*)m_ObList->GetNext(pos);
		l_item = m_list.GetItemCount();
		m_list.InsertItem(l_item, NowTask->GetName());
		m_list.SetItemText(l_item, 1, Type(NowTask->GetType()));
		m_list.SetItemText(l_item, 2, NowTask->GetTimeSpent());
		m_list.SetItemText(l_item, 3, IsVisible(NowTask->IsTaskVisible()));
		m_list.SetItemData(l_item, 0);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAllTasks::OnOK() 
{
	// TODO: Add extra validation here
	
	POSITION pos = m_ObList->GetHeadPosition();
	CTask* NowTask;
	int l_item = 0;
	while(pos != NULL)
	{
		NowTask = (CTask*)m_ObList->GetNext(pos);
		if(m_list.GetItemData(l_item))
		{
			NowTask->ChangeVisible();
		}
		l_item++;
	}


	CDialog::OnOK();
}
