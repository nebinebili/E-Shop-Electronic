#pragma once
#include<iostream>
#include "Exception.h";
using namespace std;
class Catagory {
	static int id;
	int catagoryID;
	string _name;
public:
	Catagory() :catagoryID(), _name() {};
	Catagory(const string& name)
	{
		catagoryID = ++id;
		SetName(name);
	}
	int GetId()const {
		return catagoryID;
	}
	string GetName()const {
		return _name;
	}
	void SetName(const string& name) {
		if (name == " ") throw NullException("Catagory Name is Empty", __LINE__, __FILE__, __TIME__);
		_name = name;
	}
	void CatagoryInfo() {
		cout << "Catagory Id->" << catagoryID << endl;
		cout << "Catagory Name->" << _name << endl;
	}
};
int Catagory::id = 0;
