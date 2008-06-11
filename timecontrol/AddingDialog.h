#if !defined(AFX_ADDINGDIALOG_H__A512F5AD_9EBA_4505_95D8_3A37C20EEEE4__INCLUDED_)
#define AFX_ADDINGDIALOG_H__A512F5AD_9EBA_4505_95D8_3A37C20EEEE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddingDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddingDialog dialog

class CAddingDialog : public CDialog
{
// Construction
public:
	CAddingDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddingDialog)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strProjectName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddingDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddingDialog)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDINGDIALOG_H__A512F5AD_9EBA_4505_95D8_3A37C20EEEE4__INCLUDED_)
