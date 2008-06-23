// DlgError.cpp : implementation file
//

#include "stdafx.h"
#include "TimeControl.h"
#include "DlgError.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgError dialog


CDlgError::CDlgError(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgError::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgError)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgError::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgError)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgError, CDialog)
	//{{AFX_MSG_MAP(CDlgError)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgError message handlers
