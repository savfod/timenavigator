// DlgCorrect.cpp : implementation file
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgCorrect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCorrect dialog


CDlgCorrect::CDlgCorrect(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCorrect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCorrect)
	m_Name = _T("");
	m_Hours = _T("");
	m_Minutes = _T("");
	m_Seconds = _T("");
	m_Type = -1;
	m_IsNegative = -1;
	m_NotToday = FALSE;
	//}}AFX_DATA_INIT
}


void CDlgCorrect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCorrect)
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDV_MaxChars(pDX, m_Name, 30);
	DDX_Text(pDX, IDC_EDIT2, m_Hours);
	DDV_MaxChars(pDX, m_Hours, 4);
	DDX_Text(pDX, IDC_EDIT3, m_Minutes);
	DDV_MaxChars(pDX, m_Minutes, 2);
	DDX_Text(pDX, IDC_EDIT4, m_Seconds);
	DDV_MaxChars(pDX, m_Seconds, 2);
	DDX_Radio(pDX, IDC_TYPE, m_Type);
	DDX_Radio(pDX, IDC_PLUS, m_IsNegative);
	DDX_Check(pDX, IDC_TODAY, m_NotToday);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCorrect, CDialog)
	//{{AFX_MSG_MAP(CDlgCorrect)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCorrect message handlers
