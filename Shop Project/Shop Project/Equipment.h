#pragma once
#include<iostream>
#include "Exception.h";
using namespace std;
class Equipment {
protected:
	static int id;
	int productid;
	int _catagoryId;
	string model;
	double _price;
	int quantity;
	string name;
public:
	Equipment() :_catagoryId(), model(), _price(),quantity(),name(),productid(){
		productid = ++id;
	};
	Equipment(const int catagoryId,const string&name,const string& model,const double price,const int quantity)
	{
		productid =++id;
		SetCatagoryId(catagoryId);
		SetName(name);
		SetModel(model);
		SetPrice(price);
		SetQuantity(quantity);
	}
	int GetProductID()const {
		return productid;
	}
	int GetCatagoryId()const {
		return _catagoryId;
	}
	virtual int GetQuantity()const {
		return quantity;
	}
	double GetPrice()const {
		return _price;
	}
	string GetModel()const {
		return model;
	}
	string GetName()const {
		return name;
	}
	void SetName(const string& name) {
		if (name == " ") throw NullException("Name is NULL", __LINE__, __FILE__, __TIME__);
		this->name = name;
	}
	void SetCatagoryId(const int catagoryId) {
		if (catagoryId < 0) throw InvalidArgumentException("Catagory ID is NULL", __LINE__, __FILE__, __TIME__);
		_catagoryId = catagoryId;
	}
	void SetModel(const string& model) {
		if (model == " ") throw NullException("Model is NULL", __LINE__, __FILE__, __TIME__);
		this->model = model;
	}
	void SetPrice(const double price) {
		if (price < 0) throw InvalidArgumentException("Price is smaller than 0", __LINE__, __FILE__, __TIME__);
		_price = price;
	}
	void SetQuantity(const int quantity) {
		if (quantity < 0) throw InvalidArgumentException("Quantity is smaller than 0", __LINE__, __FILE__, __TIME__);
		if (quantity >= 0) {
		 this->quantity = quantity;
		}
	}
   virtual void ShowProduct() {
		cout << "Catagory Id->" << GetCatagoryId() << endl;
		cout << "Product ID->" << GetProductID() << endl;
		cout << "Name->" << GetName() << endl;
		cout << "Model->" << GetModel() << endl;
		cout << "Price->" << GetPrice()<<" $"<< endl;
   }
   virtual void Input() {
   }
   void EquipmentShow() {
	   cout << "Product ID->" << GetProductID() << endl;
	   cout << "Name->" << GetName() << endl;
	   cout << "Model->" << GetModel() << endl;
	   cout << "Price->" << GetPrice() << " $" << endl;
	   cout << "Quantity->" << GetQuantity() << endl;
   }
   friend istream& operator>>(istream& stream, Equipment& v);
};
istream& operator>>(istream& stream, Equipment& v) {
	v.Input();
	return stream;
}
int Equipment::id = 0;
