#if !defined(AFX_DLGADDING_H__86E35830_DA5C_42D7_AB06_49E9FB46DCC1__INCLUDED_)
#define AFX_DLGADDING_H__86E35830_DA5C_42D7_AB06_49E9FB46DCC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAdding.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAdding dialog

class CDlgAdding : public CDialog
{
// Construction
public:
	CDlgAdding(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgAdding)
	enum { IDD = IDD_ADDING };
	CString	m_Name;
	int		m_Type;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAdding)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAdding)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDING_H__86E35830_DA5C_42D7_AB06_49E9FB46DCC1__INCLUDED_)
