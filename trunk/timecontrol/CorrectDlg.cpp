// CorrectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "timecontrol.h"
#include "CorrectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCorrectDlg dialog


CCorrectDlg::CCorrectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCorrectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCorrectDlg)
	m_hours = _T("");
	m_minutes = _T("");
	m_seconds = _T("");
	m_project = _T("");
	//}}AFX_DATA_INIT
}


void CCorrectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCorrectDlg)
	DDX_Text(pDX, IDC_EDIT2, m_hours);
	DDV_MaxChars(pDX, m_hours, 5);
	DDX_Text(pDX, IDC_EDIT3, m_minutes);
	DDV_MaxChars(pDX, m_minutes, 2);
	DDX_Text(pDX, IDC_EDIT4, m_seconds);
	DDV_MaxChars(pDX, m_seconds, 2);
	DDX_Text(pDX, IDC_EDIT6, m_project);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCorrectDlg, CDialog)
	//{{AFX_MSG_MAP(CCorrectDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCorrectDlg message handlers
