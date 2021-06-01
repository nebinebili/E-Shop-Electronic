#pragma once
#include<iostream>
#include "Equipment.h";
using namespace std;
class Phone:public Equipment{
	static int id;
	int phoneID;
	double _memory;
	string _mainCamera;
	string _frontCamera;
	string _screenSize;
	string _brand;
	string _color;
public:
	Phone() :_brand(),_color(),_memory(), _mainCamera(), _frontCamera(), _screenSize(),phoneID() {
		phoneID = ++id;
	};
	Phone(const int catagoryId,const string&name,const string& model,const string& brand,const string& color,const double price,
		const double memory,const string& maincamera,const string&frontcamera,const string& screenSize,const int quantity)
		:Equipment(catagoryId,name,model,price,quantity)
	{
		phoneID = ++id;
		SetMemory(memory);
		SetMainCamera(maincamera);
		SetFrontCamera(frontcamera);
		SetScreenSize(screenSize);
		SetColor(color);
		SetBrand(brand);
	}
	int GetId()const {
		return phoneID;
	}
	int GetQuantity()const override{
		return quantity;
	}
	string GetMainCamera()const {
		return _mainCamera;
	}
	string GetFrontCamera()const {
		return _frontCamera;
	}
	string GetScreenSizee()const {
		return _screenSize;
	}
	double GetMemory()const {
		return _memory;
	}
	string GetBrand()const {
		return _brand;
	}
	string GetColor()const {
		return _color;
	}
	void SetMainCamera(const string& mainCamera) {
		if (mainCamera == " ") throw NullException("Main Camera is NULL", __LINE__, __FILE__, __TIME__);
		this->_mainCamera = mainCamera;
	}
	void SetFrontCamera(const string& frontCamera) {
		if (frontCamera == " ") throw NullException("Front Camera is NULL", __LINE__, __FILE__, __TIME__);
		this->_frontCamera = frontCamera;
	}
	void SetScreenSize(const string& screenSize) {
		if (screenSize == " ") throw NullException("Screen Size is NULL", __LINE__, __FILE__, __TIME__);
		this->_screenSize = screenSize;
	}
	void SetMemory(const double memory) {
		if (memory < 0) throw InvalidArgumentException("Memory is smaller than 0", __LINE__, __FILE__, __TIME__);
		this->_memory = memory;
	}
	void SetBrand(const string& brand) {
		if (brand == " ") throw NullException("Equipment Brand is NULL", __LINE__, __FILE__, __TIME__);
		_brand = brand;
	}
	void SetColor(const string& color) {
		if (color == " ") throw NullException("Color name is NULL", __LINE__, __FILE__, __TIME__);
		_color = color;
	}
	void ShowProduct()override{
		cout << "<<<" << GetName() << ">>>" << endl;
		cout << "\nProduct ID->" << GetProductID() << endl;
		cout << "Phone ID->" << GetId() << endl;
		cout << "Product Model->" << GetModel() << endl;
		cout << "Price->" <<GetPrice() << "$" << endl;
		cout << "Product Quantity->" << GetQuantity() << endl;
		cout << "Memory->" << _memory << endl;
		cout << "Main Camera->" << _mainCamera << endl;
		cout << "Front Camera->" << _frontCamera << endl;
		cout << "Screen Size->" << _screenSize << endl;
		cout << "Color->" << _color << endl;
		cout << "Brand->" << _brand << endl << endl;
	}
	void Input()override{
		cout << "\n\n\nProduct Name->";
		cin.ignore();
		getline(cin, name);
		cout << "Phone model->";
		getline(cin,model);
		cout << "Phone Brand->";
		getline(cin, _brand);
		cout << "Phone Color->";
		getline(cin, _color);
		cout << "Phone Maincamera->";
		getline(cin, _mainCamera);
		cout << "Phone Frontcamera->";
		getline(cin, _frontCamera);
		cout << "Phone Screensize->";
		getline(cin, _screenSize);
		cout << "Catagory Id->";
		cin >> _catagoryId;
		cout << "Phone Price->";
		cin.ignore();
		cin >> _price;
		cout << "Phone Memory->";
		cin >> _memory;
		cout << "Product Quantity->";
		cin >> quantity;
	}
	friend istream& operator>>(istream& in, Phone& v);
};
istream& operator>>(istream& in, Phone& v) {
	v.Input();
	return in;
}
int Phone::id = 0;
