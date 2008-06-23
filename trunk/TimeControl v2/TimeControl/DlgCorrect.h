#if !defined(AFX_DLGCORRECT_H__2A617412_02A6_484B_9D6D_D11BCEC76BEC__INCLUDED_)
#define AFX_DLGCORRECT_H__2A617412_02A6_484B_9D6D_D11BCEC76BEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCorrect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgCorrect dialog

class CDlgCorrect : public CDialog
{
// Construction
public:
	CDlgCorrect(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgCorrect)
	enum { IDD = IDD_CORRECT };
	CString	m_Name;
	CString	m_Hours;
	CString	m_Minutes;
	CString	m_Seconds;
	int		m_Type;
	int		m_IsNegative;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgCorrect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgCorrect)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCORRECT_H__2A617412_02A6_484B_9D6D_D11BCEC76BEC__INCLUDED_)
