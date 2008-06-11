#if !defined(AFX_NEWLIST_H__679632CB_D55F_4BE2_B28E_6D19E22F9919__INCLUDED_)
#define AFX_NEWLIST_H__679632CB_D55F_4BE2_B28E_6D19E22F9919__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// NewList dialog

class NewList : public CDialog
{
// Construction
public:
	NewList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(NewList)
	enum { IDD = IDD_SureNew };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(NewList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(NewList)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWLIST_H__679632CB_D55F_4BE2_B28E_6D19E22F9919__INCLUDED_)
