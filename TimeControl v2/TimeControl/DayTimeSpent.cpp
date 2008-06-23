// DayTimeSpent.cpp: implementation of the CDayTimeSpent class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "TimeControl.h"
#include "DayTimeSpent.h"
//#include "Time.h"

IMPLEMENT_SERIAL(CDayTimeSpent, CObject, 0)

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDayTimeSpent::CDayTimeSpent()
{
	time_t NowTime;
	time(&NowTime);
	day = *localtime(&NowTime);
	seconds = 0;
}

CDayTimeSpent::~CDayTimeSpent()
{

}

CDayTimeSpent::CDayTimeSpent(const CDayTimeSpent &CDTS)
{
	seconds = CDTS.seconds;
	day = CDTS.day;
}

void CDayTimeSpent::operator=(const CDayTimeSpent& CDTS)
{
	seconds = CDTS.seconds;
	day = CDTS.day;
	
}

//////////////////////////////////////////////////////////////////////
// Other functions
//////////////////////////////////////////////////////////////////////
void CDayTimeSpent::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
	{
		ar << (LONG)seconds << (LONG)day.tm_yday << (LONG)day.tm_year;
	}
	else
	{
		ar >> (LONG&)seconds >> (LONG&)day.tm_yday >> (LONG&)day.tm_year;
	}
}