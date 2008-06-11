// TimeControlDoc.h : interface of the CTimeControlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMECONTROLDOC_H__3208EB72_F758_46FE_AF09_E56E3F21CDF7__INCLUDED_)
#define AFX_TIMECONTROLDOC_H__3208EB72_F758_46FE_AF09_E56E3F21CDF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTimeControlDoc : public CDocument
{
protected: // create from serialization only
	CTimeControlDoc();
	DECLARE_DYNCREATE(CTimeControlDoc)

// Attributes
public:

private:
	CObList AllTasks;
	CObList ActiveTasks;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeControlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTimeControlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTimeControlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROLDOC_H__3208EB72_F758_46FE_AF09_E56E3F21CDF7__INCLUDED_)
