#if !defined(AFX_CORRECTDLG_H__B58C6EA7_855E_4F9F_ADF8_83803B4A0A2B__INCLUDED_)
#define AFX_CORRECTDLG_H__B58C6EA7_855E_4F9F_ADF8_83803B4A0A2B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CorrectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCorrectDlg dialog

class CCorrectDlg : public CDialog
{
// Construction
public:
	CCorrectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCorrectDlg)
	enum { IDD = IDD_CorrectDlg };
	CString	m_hours;
	CString	m_minutes;
	CString	m_seconds;
	CString	m_project;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCorrectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCorrectDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CORRECTDLG_H__B58C6EA7_855E_4F9F_ADF8_83803B4A0A2B__INCLUDED_)
