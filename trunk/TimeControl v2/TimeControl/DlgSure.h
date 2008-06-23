#if !defined(AFX_DLGSURE_H__26A51FFB_87E5_4401_838D_68C24DAAFAC4__INCLUDED_)
#define AFX_DLGSURE_H__26A51FFB_87E5_4401_838D_68C24DAAFAC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSure.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSure dialog

class CDlgSure : public CDialog
{
// Construction
public:
	CDlgSure(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSure)
	enum { IDD = IDD_SURE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSure)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSure)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSURE_H__26A51FFB_87E5_4401_838D_68C24DAAFAC4__INCLUDED_)
