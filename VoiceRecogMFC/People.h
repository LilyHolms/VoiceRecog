#pragma once

#include <iostream>	
using namespace std;
#include <string.h>

class People
{
private:
	string Pid;
	string Pname;
	string Psex;
	string Pphone;
	string Pinfo;
	string Pimg;

public:
	void setInfo(string P_id, string P_name, string P_sex, string P_phone){
		Pid = P_id;
		Pname = P_name;
		Psex = P_sex;
		Pphone = P_phone;
	}
	void setPid(string P_id){
		Pid = P_id;
	}
	void setPname(string P_name){
		Pname = P_name;
	}
	void setPsex(string P_sex){
		Psex = P_sex;
	}
	void setPphone(string P_phone){
		Pphone = P_phone;
	}
	string getPid(){
		return Pid;
	}
	string getPname(){
		return Pname;
	}
	string getPsex(){
		return Psex;
	}
	string getPphone(){
		return Pphone;
	}

	People();
	~People();
	

};

