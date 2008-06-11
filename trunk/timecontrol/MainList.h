#if !defined(AFX_MAINLIST_H__E1CEE0A8_A0AA_44C6_B703_77D9C2142F7D__INCLUDED_)
#define AFX_MAINLIST_H__E1CEE0A8_A0AA_44C6_B703_77D9C2142F7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainList.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMainList window

class CMainList : public CListCtrl
{
// Construction
public:
	CMainList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainList)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMainList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINLIST_H__E1CEE0A8_A0AA_44C6_B703_77D9C2142F7D__INCLUDED_)
