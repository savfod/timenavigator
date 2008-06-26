// DlgAdding.cpp : implementation file
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgAdding.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAdding dialog


CDlgAdding::CDlgAdding(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAdding::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAdding)
	m_Name = _T("");
	m_Type = -1;
	//}}AFX_DATA_INIT
}


void CDlgAdding::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAdding)
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDV_MaxChars(pDX, m_Name, 30);
	DDX_Radio(pDX, IDC_TYPE, m_Type);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAdding, CDialog)
	//{{AFX_MSG_MAP(CDlgAdding)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAdding message handlers


