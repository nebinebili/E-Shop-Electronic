#pragma once
#include<iostream>
#include "Equipment.h";
using namespace std;
class Notebook:public Equipment{
	static int id;
	int notebookID;
	string _processor;
	string _cpuSpeed;
	bool _hasSSD;
	double _memory;
	string _ram;
	string _brand;
	string _color;
public:
	Notebook() :_brand(),_color(),_processor(), _cpuSpeed(), _hasSSD(), _memory(), _ram(),notebookID(){
		notebookID = ++id;
	};
	Notebook(const int catagoryId,const string& name,const string& model,const double price,const string& brand,
	 const string& color,const string& processor,const string& cpuSpeed,const bool hasSSD,const double memory,const string& ram,const int quantity)
	  :Equipment(catagoryId,name,model,price,quantity)
	{
		notebookID = ++id;
		SetProcessor(processor);
		SetCpuSpeed(cpuSpeed);
		SetHasSSD(hasSSD);
		SetMemory(memory);
		SetRam(ram);
		SetColor(color);
		SetBrand(brand);
	}
	int GetId()const {
		return notebookID;
	}
	int GetQuantity()const override {
		return quantity;
	}
	double GetMemory()const {
		return _memory;
	}
	bool GetHasSSD()const {
		return _hasSSD;
	}
	string GetProcessor()const {
		return _processor;
	}
	string GetCpuSpeed()const {
		return _cpuSpeed;
	}
	string GetRam()const {
		return _ram;
	}
	string GetBrand()const {
		return _brand;
	}
	string GetColor()const {
		return _color;
	}
	void SetBrand(const string& brand) {
		if (brand == " ") throw NullException("Equipment Brand is NULL", __LINE__, __FILE__, __TIME__);
		_brand = brand;
	}
	void SetColor(const string& color) {
		if (color == " ") throw NullException("Color name is NULL", __LINE__, __FILE__, __TIME__);
		_color = color;
	}
	void SetProcessor(const string& processor) {
		if (processor == " ") throw NullException("Processor is NULL", __LINE__, __FILE__, __TIME__);
		_processor = processor;
	}
	void SetCpuSpeed(const string& cpuSpeed) {
		if (cpuSpeed == " ") throw NullException("Cpu Speed is NULL", __LINE__, __FILE__, __TIME__);
		_cpuSpeed = cpuSpeed;
	}
	void SetRam(const string& ram) {
		if (ram == " ") throw NullException("Ram is NULL", __LINE__, __FILE__, __TIME__);
		_ram = ram;
	}
	void SetMemory(const double memory) {
		if (memory < 0) throw InvalidArgumentException("Memory is smaller than 0 or Not entered correctly", __LINE__, __FILE__, __TIME__);
		_memory = memory;
	}
	void SetHasSSD(const bool hasSSD) {
		_hasSSD = hasSSD;
	}
	void Input()override {
		cout << "\n\n\nProduct Name->";
		cin.ignore();
		getline(cin, name);
		cout << "Notebook Model->";
		getline(cin, model);
		cout << "Notebook Brand->";
		getline(cin, _brand);
		cout << "Notebook Color->";
		getline(cin, _color);
		cout << "Notebook Processor->";
		getline(cin, _processor);
		cout << "Notebook CPU Speed->";
		getline(cin, _cpuSpeed);
		cout << "Notebook RAM->";
		getline(cin, _ram);
		cout << "Catagory Id->";
		cin >> _catagoryId;
		cout << "Notebook Price->";
		cin >> _price;
		cout << "Notebook Memory->";
		cin >> _memory;
		cout << "Notebook Has SSD->";
		cin >> _hasSSD;
		cout << "Product Quantity->";
		cin >> quantity;
	}
	void ShowProduct()override{
		cout << "<<<" << GetName() << ">>>" << endl;
		cout << "\nProduct ID->" << GetProductID() << endl;
		cout << "Notebook ID->" << GetId() << endl;
		cout << "Product Model->" << GetModel() << endl;
		cout << "Price->" << GetPrice()<<"$"<< endl;
		cout << "Product Quantity->" << GetQuantity() << endl;
		cout << "Processor->" << _processor << endl;
		cout << "Cpu Speed->" << _cpuSpeed << endl;
		if (_hasSSD == true) {
			cout << "Has SSD->Yes" << endl;
		}
		else if (_hasSSD == false) {
			cout << "Has SSD->NO" << endl;
		}
		cout << "Color->" << _color << endl;
		cout << "Brand->" << _brand << endl;
		cout << "Memory->" << _memory << endl;
		cout << "Ram->" << _ram << endl << endl;
	}
	friend istream& operator>>(istream& in, Notebook& v);
};
istream& operator>>(istream& in, Notebook& v) {
	v.Input();
	return in;
}
int Notebook::id = 0;
