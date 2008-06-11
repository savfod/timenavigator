// AddingDialog.cpp : implementation file
//

#include "stdafx.h"
#include "timecontrol.h"
#include "AddingDialog.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddingDialog dialog


CAddingDialog::CAddingDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddingDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddingDialog)
	m_strProjectName = _T("");
	//}}AFX_DATA_INIT
}


void CAddingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddingDialog)
	DDX_Text(pDX, IDC_EDIT3, m_strProjectName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddingDialog, CDialog)
	//{{AFX_MSG_MAP(CAddingDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddingDialog message handlers

void CAddingDialog::OnOK() 
{
	// TODO: Add extra validation here
		
	CDialog::OnOK();
}
