#pragma once
#include"Exception.h"
#include<iostream>
using namespace std;
class Person {
	string username;
	string password;
public:
	Person(const string& username, const string& password)
	{
		SetUsername(username);
		SetPassword(password);
	}
	string GetUsername()const {
		return username;
	}
	string GetPassword()const {
		return password;
	}
	void SetUsername(const string username) {
		if (username == " ") {
			throw NullException(" Username is Empty", __LINE__, __FILE__, __TIME__);
		}
		this->username = username;
	}
	void SetPassword(const string password) {
		if (password == " ") {
			throw NullException("Password is Empty", __LINE__, __FILE__, __TIME__);
		}
		this->password = password;
	}
	virtual void Show() {
		cout << "Username->" << username << endl;
		cout << "Password->" << password << endl;
	}
};
