// SureDlg.cpp : implementation file
//

#include "stdafx.h"
#include "timecontrol.h"
#include "SureDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSureDlg dialog


CSureDlg::CSureDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSureDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSureDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSureDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSureDlg, CDialog)
	//{{AFX_MSG_MAP(CSureDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSureDlg message handlers

