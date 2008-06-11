// timecontrolDoc.h : interface of the CTimecontrolDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMECONTROLDOC_H__09717875_F262_4A59_BE0F_0C0EB6DADB09__INCLUDED_)
#define AFX_TIMECONTROLDOC_H__09717875_F262_4A59_BE0F_0C0EB6DADB09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTimecontrolDoc : public CDocument
{
protected: // create from serialization only
	CTimecontrolDoc();
	DECLARE_DYNCREATE(CTimecontrolDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimecontrolDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTimecontrolDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTimecontrolDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMECONTROLDOC_H__09717875_F262_4A59_BE0F_0C0EB6DADB09__INCLUDED_)
