// TimeControlDoc.cpp : implementation of the CTimeControlDoc class
//

#include "stdafx.h"
#include "TimeControl.h"
#include "Task.h"

#include "TimeControlDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTimeControlDoc

IMPLEMENT_DYNCREATE(CTimeControlDoc, CDocument)

BEGIN_MESSAGE_MAP(CTimeControlDoc, CDocument)
	//{{AFX_MSG_MAP(CTimeControlDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTimeControlDoc construction/destruction

CTimeControlDoc::CTimeControlDoc()
{
	// TODO: add one-time construction code here

}

CTimeControlDoc::~CTimeControlDoc()
{
}

BOOL CTimeControlDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTimeControlDoc serialization

void CTimeControlDoc::Serialize(CArchive& ar)
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
// CTimeControlDoc diagnostics

#ifdef _DEBUG
void CTimeControlDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTimeControlDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTimeControlDoc commands
