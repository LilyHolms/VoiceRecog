#pragma once
#include <iostream>
using namespace std;
#include <list>
#include "People.h"

class ADO
{
public:
	ADO(void);
	~ADO(void);
	void OnInitADOConn(void);
	void CloseRecordset(void);
	void CloseConn(void);
	UINT GetRecordCount(_RecordsetPtr pRecordset);

	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	_RecordsetPtr& OpenRecordset(CString sql);

	list<People> static getPeopleByName(string name);

};

