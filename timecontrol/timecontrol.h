// timecontrol.h : main header file for the TIMECONTROL application
//

#if !defined(AFX_TIMECONTROL_H__A8E17A44_951E_4CF5_957C_4DBCDD8A7348__INCLUDED_)
#define AFX_TIMECONTROL_H__A8E17A44_951E_4CF5_957C_4DBCDD8A7348__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolApp:
// See timecontrol.cpp for the implementation of this class
//

class CTimecontrolApp : public CWinApp
{
public:
	CTimecontrolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimecontrolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTimecontrolApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROL_H__A8E17A44_951E_4CF5_957C_4DBCDD8A7348__INCLUDED_)
