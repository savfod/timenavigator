// NewList.cpp : implementation file
//

#include "stdafx.h"
#include "timecontrol.h"
#include "NewList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// NewList dialog


NewList::NewList(CWnd* pParent /*=NULL*/)
	: CDialog(NewList::IDD, pParent)
{
	//{{AFX_DATA_INIT(NewList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void NewList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(NewList)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(NewList, CDialog)
	//{{AFX_MSG_MAP(NewList)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// NewList message handlers
