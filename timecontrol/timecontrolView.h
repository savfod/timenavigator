// timecontrolView.h : interface of the CTimecontrolView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMECONTROLVIEW_H__5ED1E5DD_AF91_4648_AD8A_A1CD73AEC7F3__INCLUDED_)
#define AFX_TIMECONTROLVIEW_H__5ED1E5DD_AF91_4648_AD8A_A1CD73AEC7F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "NowProjectTimeCounter.h"




class CTimecontrolView : public CFormView
{
protected: // create from serialization only
	CTimecontrolView();
	DECLARE_DYNCREATE(CTimecontrolView)

public:
	//{{AFX_DATA(CTimecontrolView)
	enum { IDD = IDD_TIMECONTROL_FORM };
	CListCtrl	m_list;
	//}}AFX_DATA

// Attributes
public:
	CTimecontrolDoc* GetDocument();
	CString		m_DataCode;
	CString		m_Time;
	
	TCHAR m_StandartSavePlace[200];
	bool wasSaved;
	
	int			g_img_column_data;



protected:

	CNowProjectTimeCounter TimeCounter;
	
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimecontrolView)
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
	virtual ~CTimecontrolView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTimecontrolView)
	afx_msg void Onaddtask();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnStopTime();
	afx_msg void OnDelete();
	afx_msg void Oncorrect();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileSave();
	afx_msg void OnFileNew();
	afx_msg void OnMenuitem32785();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in timecontrolView.cpp
inline CTimecontrolDoc* CTimecontrolView::GetDocument()
   { return (CTimecontrolDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROLVIEW_H__5ED1E5DD_AF91_4648_AD8A_A1CD73AEC7F3__INCLUDED_)
