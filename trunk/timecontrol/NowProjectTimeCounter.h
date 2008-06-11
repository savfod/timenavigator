// NowProjectTimeCounter.h: interface for the CNowProjectTimeCounter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOWPROJECTTIMECOUNTER_H__DA3BF37E_48D0_400A_B4AF_9B48816C63B4__INCLUDED_)
#define AFX_NOWPROJECTTIMECOUNTER_H__DA3BF37E_48D0_400A_B4AF_9B48816C63B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <time.h>
#include <cstring>
#include <string>


class CNowProjectTimeCounter  
{
public:
	CNowProjectTimeCounter();
	virtual ~CNowProjectTimeCounter();

	CString TimeUpdate();
	void newNowProject(int newIndex, CString newStartTime);
	int TakeIndex();

private:
	int index;  //index of now-working project
	time_t StartTime;
	CString s_StartTime;   // Start time in format h:m:s (for ex. 1:02:01)

	CString StringTimeIncrease(int seconds);   //increase time in string (1:02:01) format
	int StoI(CString time);
	CString ItoS(int seconds);

};

#endif // !defined(AFX_NOWPROJECTTIMECOUNTER_H__DA3BF37E_48D0_400A_B4AF_9B48816C63B4__INCLUDED_)
