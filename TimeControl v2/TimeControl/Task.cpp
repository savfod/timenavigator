// Task.cpp: implementation of the CTask class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TimeControl.h"
#include "Task.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTask::CTask(int type)
{
	TypeOfTask = type;
}

CTask::~CTask()
{

}

void CTask::Serialize(CArchive& ar)
{
}


void CTask::SetIndex(