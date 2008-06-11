// TimeControl.h : main header file for the TIMECONTROL application
//

#if !defined(AFX_TIMECONTROL_H__2FDFBBBA_B195_44AB_B29E_6F22C358D38C__INCLUDED_)
#define AFX_TIMECONTROL_H__2FDFBBBA_B195_44AB_B29E_6F22C358D38C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeControlApp:
// See TimeControl.cpp for the implementation of this class
//

class CTimeControlApp : public CWinApp
{
public:
	CTimeControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTimeControlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROL_H__2FDFBBBA_B195_44AB_B29E_6F22C358D38C__INCLUDED_)
