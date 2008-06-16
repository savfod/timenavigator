// Task.cpp: implementation of the CTask class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TimeControl.h"
#include "Task.h"

IMPLEMENT_SERIAL(CTask, CObject, 0)

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTask::CTask()
{
}
CTask::CTask(int type,CString GetName)
{
	TypeOfTask = type;
	Name = GetName;
	
	IsVisible = TRUE; //it isn't in archieve 
	s_TimeSpent = "0:00:00"; //time spent on task in string (1:02:01) format
	//m_IsActive = TRUE;
	
	
}

CTask::~CTask()
{

}

void CTask::Serialize(CArchive& ar)
{
	if(ar.IsStoring())
	{
		ar << Name << (LONG)IsVisible << s_TimeSpent << (LONG)TypeOfTask;
	}
	else
	{
		ar >> Name >> (LONG&)IsVisible >> s_TimeSpent >> (LONG&)TypeOfTask;
	}
}



int CTask::StoI(CString time)
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







CString CTask::ItoS(int seconds)
{
	CString s;

	if(seconds<0)
		return (s);

	s = ':';

	
	int hours = seconds/3600;
	int minutes = seconds/60 - 60*hours;
	int trueseconds = seconds - 60*minutes - 3600 * hours;
	
	

	CString s_hours;
	s_hours.Format(_T("%d"), hours);

	


	
	CString s_minutes;
	s_minutes.Format(_T("%.2d"), minutes);

	
	
	CString s_seconds;
	s_seconds.Format(_T("%.2d"), trueseconds);


return (s_hours + s + s_minutes + s + s_seconds);
}

CString CTask::StringTimeIncrease(int seconds)   //increase time in string (1:02:01) format
{
	int time = StoI(s_StartTime);//
	
	if(time + seconds>0)
	return( ItoS (time + seconds));

	else 
	return( ItoS (0));
}


void CTask::StartTime()
{
	t_StartTime = time(NULL);
	s_StartTime = s_TimeSpent;//
}
void CTask::StopTime()
{
	s_TimeSpent = TimeUpdate();
}	



CString CTask::Correct(CString NewName, bool IsNegative, CString hours, CString minutes, CString seconds)
{
	s_StartTime = s_TimeSpent;//
	Name = NewName;
	
	hours.SpanIncluding("0123456789");
	minutes.SpanIncluding("0123456789");
	seconds.SpanIncluding("0123456789");
	
	int m_hours = atoi(hours);
	int m_minutes = atoi(minutes);
	int m_seconds = atoi(seconds);
	
	int time = 3600*m_hours + 60*m_minutes + m_seconds;
	
	if(IsNegative)
		time = -time;
	s_TimeSpent = StringTimeIncrease(time);
	return(s_TimeSpent);
}


CString CTask::TimeUpdate()
{
	time_t now;
	now = time(NULL);
	
	int difference = (int)difftime(now, t_StartTime);
	
	s_TimeSpent = StringTimeIncrease(difference);//
	return(s_TimeSpent);//
}









void CTask::Archive()
{
	IsVisible = FALSE;
}

void CTask::UnArchive()
{
	IsVisible = TRUE;
}


CString CTask::GetName()
{
	return(Name);
}




/*CString CTask::GetHours()
{
	int length = s_TimeSpent.GetLength();
	return( s_TimeSpent.Left(length-6)); // without :00:00
}

CString CTask::GetSeconds()
{
	return( s_TimeSpent.Right(2));
}

CString CTask::GetMinutes()
{
	CString s; //will be minutes
	s = s_TimeSpent.Right(5); // 0:  11:00
	return( s.Left(2)); // 11  :00
}*/

int CTask::GetType()
{
	return(TypeOfTask);
}


bool CTask::IsTaskVisible()
{ 
	return(IsVisible);
}
CString CTask::GetTimeSpent()
{
	return(s_TimeSpent);
}