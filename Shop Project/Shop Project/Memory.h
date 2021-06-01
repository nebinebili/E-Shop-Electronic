#pragma once
#include<iostream>
#include"Exception.h";
#include"Equipment.h";
class Memory:public Equipment{
	static int id;
	int memoryID;
	string capacity;
	string memory_techg;
public:
	Memory() :capacity(), memory_techg(),memoryID() {
		memoryID = ++id;
	};
	Memory(const int catagoryID,const string&name,const string& model, const string& capacity, const string& memory_techg, 
		const double price,const int quantity)
	:Equipment(catagoryID,name,model,price,quantity)
	{
		memoryID = ++id;
		SetCapacity(capacity);
		SetMemoryTechg(memory_techg);
	}
	int GetId()const {
		return memoryID;
	}
	int GetQuantity()const override {
		return quantity;
	}
	string GetCapacity()const {
		return capacity;
	}
	string GetMemoryTechg()const {
		return memory_techg;
	}
	void SetCapacity(const string& capacity) {
		if (capacity == " ") throw NullException("Capacity is NULL", __LINE__, __FILE__, __TIME__);
		this->capacity = capacity;
	}
	void SetMemoryTechg(const string& memory_techg) {
		if (memory_techg == " ") throw NullException("Memory Technology is NULL", __LINE__, __FILE__, __TIME__);
		this->memory_techg = memory_techg;
	}
	void Input()override {
		cout << "\n\n\nProduct Name->";
		cin.ignore();
		getline(cin, name);
		cout << "Memory Model->";
		getline(cin, model);
		cout << "Memory Capacity->";
		getline(cin, capacity);
		cout << "Memory Technology->";
		getline(cin, memory_techg);
		cout << "Catagory Id->";
		cin >> _catagoryId;
		cout << "Price->";
		cin >> _price;
		cout << "Quantity->";
		cin >> quantity;
	}
	void ShowProduct()override{
		cout << "<<<" << GetName() << ">>>" << endl;
		cout << "\nProduct ID->" << GetProductID() << endl;
		cout << "Memory ID->" << GetId() << endl;
		cout << "Product Model->" << GetModel() << endl;
		cout << "Price->" <<GetPrice() << "$" << endl;
		cout << "Product Quantity->" << GetQuantity() << endl;
		cout << "Capacity->" << capacity << endl;
		cout << "Memory Technology->" << memory_techg << endl << endl;
	}
	friend istream& operator>>(istream& in, Memory& v);
};
istream& operator>>(istream& in, Memory& v) {
	v.Input();
	return in;
}
int Memory::id = 0;
