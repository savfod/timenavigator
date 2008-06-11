// timecontrolDoc.cpp : implementation of the CTimecontrolDoc class
//

#include "stdafx.h"
#include "timecontrol.h"

#include "timecontrolDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolDoc

IMPLEMENT_DYNCREATE(CTimecontrolDoc, CDocument)

BEGIN_MESSAGE_MAP(CTimecontrolDoc, CDocument)
	//{{AFX_MSG_MAP(CTimecontrolDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolDoc construction/destruction

CTimecontrolDoc::CTimecontrolDoc()
{
	// TODO: add one-time construction code here

}

CTimecontrolDoc::~CTimecontrolDoc()
{
}

BOOL CTimecontrolDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTimecontrolDoc serialization

void CTimecontrolDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolDoc diagnostics

#ifdef _DEBUG
void CTimecontrolDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTimecontrolDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTimecontrolDoc commands
