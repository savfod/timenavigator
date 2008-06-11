// Task.h: interface for the CTask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASK_H__4C7D975F_C469_4D99_A42E_908D4B6C6009__INCLUDED_)
#define AFX_TASK_H__4C7D975F_C469_4D99_A42E_908D4B6C6009__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTask : public CObject 
{
public:
	CTask(int Type);
	virtual ~CTask();



	void Correct(bool IsPlus, CString hours, CString minutes, CString seconds);
	CString TimeUpdate();
	void StartTime();
	int SetIndex();
	void Serialize(CArchive& ar);
	void Archive();
private:

	
	//all time parametres
	bool IsVisible; //it isn't in archieve 
	CString s_TimeSpent; //time spent on task in string (1:02:01) format
	int TypeOfTask; // 1 - work, 0 - rest

	//now parametres
	bool m_IsActive;
	time_t t_StartTime; //when became active
	CString s_StartTime; //how many time have been spent on project, when it became active
	int m_index; // now index (if is visible);


	//functions
	CString StringTimeIncrease(int seconds);   //increase time in string (1:02:01) format
	int StoI(CString time);
	CString ItoS(int seconds);


};

#endif // !defined(AFX_TASK_H__4C7D975F_C469_4D99_A42E_908D4B6C6009__INCLUDED_)
