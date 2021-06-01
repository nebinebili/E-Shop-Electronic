#pragma once
#include<iostream>
using namespace std;
class Exception {
protected:
	string text;
	int line;
	string file;
	string createdTime;
	Exception(const string& text, const int line, const string& file, const string& createdTime)
	{
		setText(text);
		setLine(line);
		setFile(file);
		setTime(createdTime);
	}
	string getText()const {
		return text;
	}
	int getLine()const {
		return line;
	}
	string getFile()const {
		return file;
	}
	string getTime()const {
		return createdTime;
	}
	void setText(const string& text) {
		if (text.empty()) throw "Text is empty";
		this->text = text;
	}
	void setLine(const int line) {
		if (line < 0) throw "Line cannot be negative";
		this->line = line;
	}
	void setFile(const string& file) {
		if (file.empty()) throw "Source is empty";
		this->file = file;
	}
	void setTime(const string& createdTime) {
		if (createdTime.empty()) throw "Time is NULL";
		time_t currently = time(0);
		char dt[30]{};
		ctime_s(dt, sizeof dt, &currently);
		string time = dt;
		this->createdTime = dt;
	}
public:
	void PrintMsg()const {
		cout << endl;
		cout << "Text:" << getText() << endl;
		cout << "Line:" << getLine() << endl;
		cout << "Source:" << getFile() << endl;
		cout << "Time: " << getTime() << endl;
	}
	virtual ~Exception() = 0
	{
	}
};
class DatabaseException :public Exception {
public:
	DatabaseException(const string& text, const int line, const string& source, const string& createdTime)
		:Exception(text, line, source, createdTime)
	{
	}
};
class InvalidArgumentException :public Exception {
public:
	InvalidArgumentException(const string& text, const int line, const string& source, const string& createdTime)
		:Exception(text, line, source, createdTime)
	{
	}
};
class NullException :public Exception {
public:
	NullException(const string& text, const int line, const string& source, const string& createdTime)
		:Exception(text, line, source, createdTime)
	{
	}
};
