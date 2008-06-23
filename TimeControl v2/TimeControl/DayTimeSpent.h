// DayTimeSpent.h: interface for the CDayTimeSpent class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAYTIMESPENT_H__10B37FFA_380B_4742_954A_7A6B865CFE7B__INCLUDED_)
#define AFX_DAYTIMESPENT_H__10B37FFA_380B_4742_954A_7A6B865CFE7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDayTimeSpent : public CObject  
{

	DECLARE_SERIAL(CDayTimeSpent)


public:
	CDayTimeSpent();
	virtual ~CDayTimeSpent();
	CDayTimeSpent(const CDayTimeSpent& CDTS);
	void operator = (const CDayTimeSpent &CDTS);
	

	struct tm day;
	int seconds;
	void Serialize(CArchive& ar);
};

#endif // !defined(AFX_DAYTIMESPENT_H__10B37FFA_380B_4742_954A_7A6B865CFE7B__INCLUDED_)
