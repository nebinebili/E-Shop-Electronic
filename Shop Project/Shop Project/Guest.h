#pragma once
#include<iostream>
#include<ctime>
#include "Person.h";
using namespace std;
class Guest :public Person {
	static int id;
	int personID;
	string fullname;
	string connected_date;
public:
	Guest(const string& username, const string& password, const string& fullname, const string& connected_date)
		:Person(username, password)
	{
		personID = ++id;
		SetFullname(fullname);
		SetConnectedDate(connected_date);
	}
	int GetPersonId()const {
		return personID;
	}
	string GetFullname()const {
		return fullname;
	}
	string GetConnentedDate()const {
		return connected_date;
	}
	void SetConnectedDate(const string connected_date) {
		if (connected_date.empty()) return;
		time_t currently = time(0);
		char dt[30]{};
		ctime_s(dt, sizeof dt, &currently);
		string time = dt;
		this->connected_date = dt;
	}
	void SetFullname(const string fullname) {
		if (fullname == " ") {
			throw NullException("Fullname is Empty", __LINE__, __FILE__, __TIME__);
		}
		this->fullname = fullname;
	}
	void Show()override {
		cout << "ID->" << personID << endl;
		cout << "Username->" << GetUsername() << endl;
		cout << "Fullname->" << fullname << endl;
		cout << "Connented Date->" << connected_date << endl;
		cout << "----------------------------------------------" << endl << endl;
	}
};
int Guest::id = 0;
