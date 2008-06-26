// Task.h: interface for the CTask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASK_H__4C7D975F_C469_4D99_A42E_908D4B6C6009__INCLUDED_)
#define AFX_TASK_H__4C7D975F_C469_4D99_A42E_908D4B6C6009__INCLUDED_
#include <afxtempl.h>		///MFC templates
#include "DayTimeSpent.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTask : public CObject 
{

	DECLARE_SERIAL(CTask)


public:
	CTask();
	CTask(int Type, CString GetName);
	virtual ~CTask();



	CString Correct(CString NewName, int IsNegative, bool NotToday, CString hours, CString minutes, CString seconds);
	CString TimeUpdate();
	void StartTime();
	void StopTime();
	CString GetName();
	void Serialize(CArchive& ar);
	void Archive();
	void UnArchive();
	/*CString GetHours();
	CString GetMinutes();
	CString GetSeconds();*/
	CString GetTimeSpent();
	int GetType();
	bool IsTaskVisible();
	void ChangeVisible();
	void NewDay();
	void TestNewDay(struct tm* day);
	CString GetTimeSpentToday();
	//all time parametres
	CArray < CDayTimeSpent, CDayTimeSpent > ArrayTimeDay;

private:

	
	//all time parametres
	CString Name;
	bool IsVisible; //it isn't in archieve 
	CString s_TimeSpent; //time spent on task in string (1:02:01) format  (in fact, how many time was spent on task, when it become active(s_StartTime))
	int TypeOfTask; // 0 - work, 1 - rest

	//now parametres
	
	//bool m_IsActive; - is not in use
	int nStartTimeToday; //how many seconds was spent today on project, when it became active
	time_t t_StartTime; //when became active
	CString s_StartTime; //how many time had been spent on project, when it became active
	
	//int m_index; // now index (if is visible); 


	//functions
	CString StringTimeIncrease(int seconds);   //increase time in string (1:02:01) format
	int StoI(CString time);
	CString ItoS(int seconds);


};

#endif // !defined(AFX_TASK_H__4C7D975F_C469_4D99_A42E_908D4B6C6009__INCLUDED_)
