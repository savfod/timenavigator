// TimeControlView.h : interface of the CTimeControlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMECONTROLVIEW_H__94E2E578_6EBE_44BF_8C5D_7384B0311C53__INCLUDED_)
#define AFX_TIMECONTROLVIEW_H__94E2E578_6EBE_44BF_8C5D_7384B0311C53__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTimeControlView : public CFormView
{
protected: // create from serialization only
	CTimeControlView();
	DECLARE_DYNCREATE(CTimeControlView)

public:
	//{{AFX_DATA(CTimeControlView)
	enum { IDD = IDD_TIMECONTROL_FORM };
	CListCtrl	m_list;
	//}}AFX_DATA

// Attributes
public:

private:
	
	POSITION p_NowActiveProject;
	int NowActiveProject;
	bool IsColumnes;// if there are columnes, or they should be added
// Operations
public:
	CTimeControlDoc* GetDocument();
	CString Type(int int_type);
	int m_nPage;
	
private:
	void StartTime();
	
	CString Archive(bool IsInArchive);
	void FindActive();
	void KillTime();
	void TestDayToday();
	void NewDay();

	//print
	void PrintPageHeader(CDC* pDC);
	void PrintPageFooter(CDC* pDC);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeControlView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTimeControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTimeControlView)
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void Onaddtask();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStopTime();
	afx_msg void OnDelete();
	afx_msg void Oncorrect();
	afx_msg void OnArchive();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnShowAll();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TimeControlView.cpp
inline CTimeControlDoc* CTimeControlView::GetDocument()
   { return (CTimeControlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROLVIEW_H__94E2E578_6EBE_44BF_8C5D_7384B0311C53__INCLUDED_)
