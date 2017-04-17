//ADO.cpp  
#include "stdafx.h"  
#include "ADO.h"  
#include <string>
#include <iostream>
using namespace std;


ADO::ADO(void)
{
}
ADO::~ADO(void)
{
}
void ADO::OnInitADOConn(void)
{

	::CoInitialize(NULL);
	try
	{
		m_pConnection.CreateInstance("ADODB.Connection");
		_bstr_t strConnect = "Data Source=VoiceRecogDB;User ID=sa;Password=admin123";
		//"Driver={sql server};server=DESKTOP-813MVV1\SQLEXPRESS;uid=sa;pwd=admin123"
		//data source后添数据库文件相对路径或绝对路径均可。  
		m_pConnection->Open(strConnect, "", "", adModeUnknown);
	}

	catch (_com_error t)
	{
		AfxMessageBox(t.Description());
	}
}


_RecordsetPtr& ADO::OpenRecordset(CString sql)
{
	//TODO: insertreturn statement here  
	ASSERT(!sql.IsEmpty());
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(_bstr_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch (_com_error t)
	{
		AfxMessageBox(t.Description());
	}
	return m_pRecordset;
}
void ADO::CloseRecordset(void)
{
	if (m_pRecordset->GetState() == adStateOpen)
		m_pRecordset->Close();
}
void ADO::CloseConn(void)
{
	m_pConnection->Close();
	::CoUninitialize();
}
UINT ADO::GetRecordCount(_RecordsetPtr pRecordset)
{
	int count = 0;
	try
	{
		pRecordset->MoveFirst();
	}
	catch (...)
	{
		return 0;
	}

	if (pRecordset->adoEOF)
		return 0;
	while (!pRecordset->adoEOF)
	{
		pRecordset->MoveNext();
		count = count + 1;
	}
	pRecordset->MoveFirst();
	return count;
}

list<People> ADO::getPeopleByName(string name){
	list<People> list_People;
	ADO m_ado;
	m_ado.OnInitADOConn();
	CString sql;
	string sql_temp = "select * from People where Pname = '" + name + "'";
	sql = CString(sql_temp.c_str());
	cout << sql_temp << endl;
	m_ado.m_pRecordset = m_ado.OpenRecordset(sql);
	while (!m_ado.m_pRecordset->adoEOF)
	{	
		printf("2:%s", (char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("Psex"));
		People thisPerson = People();
		thisPerson.setPid((char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("Pid"));
		thisPerson.setPname((char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("Pname"));
		thisPerson.setPsex((char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("Psex"));
		thisPerson.setPphone((char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("Pphone"));
		list_People.push_back(thisPerson);
		//m_show.InsertItem(0, "");
		//m_show.SetItemText(0, 0, (char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("id"));
		//m_show.SetItemText(0, 1, (char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("mediaName"));
		//m_show.SetItemText(0, 2, (char*)(_bstr_t)m_ado.m_pRecordset->GetCollect("mediaPath"));
		m_ado.m_pRecordset->MoveNext();
	}
	m_ado.CloseRecordset();
	m_ado.CloseConn();

	return list_People;
}