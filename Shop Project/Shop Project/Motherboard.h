#pragma once
#include<iostream>
#include"Exception.h";
#include"Equipment.h";
using namespace std;
class Motherboard:public Equipment{
	static int id;
	int motherboardID;
	int memory_slot;
	string cpu_socket;
	string supported_motherboard;
public:
	Motherboard() : memory_slot(), cpu_socket(), supported_motherboard(),motherboardID() {
		motherboardID = ++id;
	};
	Motherboard(const int catagoryID,const string&name,const string& model, const double price, const int quantity, 
	const int memory_slot,const string& cpu_socket, const string& supported_motherboard)
	 :Equipment(catagoryID,name,model,price,quantity)
	{
		motherboardID = ++id;
		SetMemoryslot(memory_slot);
		SetCpuSocket(cpu_socket);
		SetSupportedMotherboard(supported_motherboard);
		SetName(name);
	}
	int GetId()const {
		return motherboardID;
	}
	int GetQuantity()const override {
		return quantity;
	}
	int GetMemorySlot()const {
		return memory_slot;
	}
	string GetCpusocket()const {
		return cpu_socket;
	}
	string GetsupportedMotherboard()const{
		return supported_motherboard;
	}
	void SetMemoryslot(const int memory_slot) {
		if (memory_slot < 0)throw InvalidArgumentException("Memory Slot is smaller than 0", __LINE__, __FILE__, __TIME__);
		this->memory_slot = memory_slot;
	}
	void SetCpuSocket(const string& cpu_socket) {
		if (cpu_socket == " ")throw NullException("Cpu socket is NULL", __LINE__, __FILE__, __TIME__);
		this->cpu_socket = cpu_socket;
	}
	void SetSupportedMotherboard(const string& supported_motherboard) {
		if (supported_motherboard == " ")throw NullException("Supported Motherboard is NULL", __LINE__, __FILE__, __TIME__);
		this->supported_motherboard = supported_motherboard;
	}
	void Input()override {
		cout << "\n\n\nProduct Name->";
		cin.ignore();
		getline(cin, name);
		cout << "Motherboard Model->";
		getline(cin, model);
		cout << "Cpu socket->";
		getline(cin, cpu_socket);
		cout << "Supported Motherboard->";
		getline(cin, supported_motherboard);
		cout << "Catagory Id->";
		cin >> _catagoryId;
		cout << "Memory slot->";
		cin >> memory_slot;
		cout << "Price->";
		cin >> _price;
		cout << "Quantity->";
		cin >> quantity;
	}
	void ShowProduct()override{
		cout << "<<<" << GetName() << ">>>" << endl;
		cout << "\nProduct ID->" << GetProductID() << endl;
		cout << "Motherboard ID->" << GetId() << endl;
		cout << "Product Model->" <<GetModel() << endl;
		cout << "Price->" << GetPrice() << "$" << endl;
		cout << "Product Quantity->" << GetQuantity() << endl;
		cout << "Memory Slot->" << memory_slot << endl;
		cout << "CPU Socket->" << cpu_socket << endl;
		cout << "Supported Motherboard->" << supported_motherboard << endl << endl;
	}
	friend istream& operator>>(istream& in, Motherboard& v);
};
istream& operator>>(istream& in, Motherboard& v) {
	v.Input();
	return in;
}
int Motherboard::id = 0;
