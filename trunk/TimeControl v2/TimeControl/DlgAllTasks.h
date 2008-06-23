#if !defined(AFX_DLGALLTASKS_H__E9975063_6A17_4B35_8042_9F1BE0D0821F__INCLUDED_)
#define AFX_DLGALLTASKS_H__E9975063_6A17_4B35_8042_9F1BE0D0821F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAllTasks.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAllTasks dialog

class CDlgAllTasks : public CDialog
{
// Construction
public:
	CDlgAllTasks(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	CObList* m_ObList;
	//{{AFX_DATA(CDlgAllTasks)
	enum { IDD = IDD_ALL };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAllTasks)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString Type(int type);
	CString IsVisible(bool IsVis);
	int FindActive();
	CString ChangeActive(CString now);
	// Generated message map functions
	//{{AFX_MSG(CDlgAllTasks)
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGALLTASKS_H__E9975063_6A17_4B35_8042_9F1BE0D0821F__INCLUDED_)
