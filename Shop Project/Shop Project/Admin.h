#pragma once
#include<iostream>
#include"Person.h"
using namespace std;
class Admin :public Person {
	static int id;
	int adminID;
public:
	Admin(const string& username, const string& password)
		:Person(username, password)
	{
		adminID = ++id;
	}
	int GetAdminId()const{
		return adminID;
	}
};
int Admin::id = 0;
