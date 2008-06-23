#if !defined(AFX_DLGERROR_H__C6AEA152_7D64_41B2_9A7E_92FC507D84CA__INCLUDED_)
#define AFX_DLGERROR_H__C6AEA152_7D64_41B2_9A7E_92FC507D84CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgError.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgError dialog

class CDlgError : public CDialog
{
// Construction
public:
	CDlgError(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgError)
	enum { IDD = IDD_ERROR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgError)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgError)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGERROR_H__C6AEA152_7D64_41B2_9A7E_92FC507D84CA__INCLUDED_)
