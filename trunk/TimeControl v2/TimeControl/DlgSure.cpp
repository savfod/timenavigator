// DlgSure.cpp : implementation file
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgSure.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSure dialog


CDlgSure::CDlgSure(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSure::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSure)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgSure::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSure)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSure, CDialog)
	//{{AFX_MSG_MAP(CDlgSure)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSure message handlers
