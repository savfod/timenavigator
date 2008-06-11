// NowProjectTimeCounter.cpp: implementation of the CNowProjectTimeCounter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "timecontrol.h"
#include "NowProjectTimeCounter.h"
#include <math.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CNowProjectTimeCounter::CNowProjectTimeCounter()
{

}

CNowProjectTimeCounter::~CNowProjectTimeCounter()
{

}


//////////////////////////////////////////////////////////////////////
int CNowProjectTimeCounter :: StoI(CString time)
{
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	
	int length = time.GetLength();
	
	for(int i = 0; i < length - 6 ; i++)
	{
		hours *= 10;
		hours += (time.GetAt(i) - '0');
	}
	minutes = 10 * (time.GetAt(length - 5) - '0') + (time.GetAt(length - 4) - '0');
	seconds = 10 * (time.GetAt(length - 2) - '0') + (time.GetAt(length - 1) - '0');


	seconds = 3600*hours + 60*minutes + seconds;
	return (seconds);
}

CString CNowProjectTimeCounter :: ItoS(int seconds)
{
	CString s;

	if(seconds<0)
		return (s);

	s = ':';

	
	int hours = seconds/3600;
	int minutes = seconds/60 - 60*hours;
	int trueseconds = seconds - 60*minutes - 3600 * hours;
	
	int number;  // number of digit

    
	

	number = hours;
	int i;
	for( i = 0; number>0 ; i++)
		number /= 10;
	number = i + 1;


	CString s_hours;
	s_hours.Format(_T("%d"), hours);

	


	
	CString s_minutes;
	s_minutes.Format(_T("%.2d"), minutes);

	
	
	CString s_seconds;
	s_seconds.Format(_T("%.2d"), trueseconds);


return (s_hours + s + s_minutes + s + s_seconds);
}


CString CNowProjectTimeCounter :: StringTimeIncrease(int seconds)
{
	int time = StoI(s_StartTime);
	
	return( ItoS (time + seconds));
}



CString CNowProjectTimeCounter :: TimeUpdate()
{
	time_t now;
	now = time(NULL);
	
	int difference = difftime(now, StartTime);
	
	return(StringTimeIncrease(difference));
}



void CNowProjectTimeCounter :: newNowProject(int newIndex, CString newStartTime)
{

	index = newIndex;
	s_StartTime = newStartTime;
	StartTime = time(NULL);
}

int CNowProjectTimeCounter :: TakeIndex()
{
	return index;
}