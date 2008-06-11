#if !defined(AFX_SUREDLG_H__ED7537C9_E676_4E63_9162_E70A736C8833__INCLUDED_)
#define AFX_SUREDLG_H__ED7537C9_E676_4E63_9162_E70A736C8833__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SureDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSureDlg dialog

class CSureDlg : public CDialog
{
// Construction
public:
	CSureDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSureDlg)
	enum { IDD = IDD_Suse };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSureDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUREDLG_H__ED7537C9_E676_4E63_9162_E70A736C8833__INCLUDED_)
