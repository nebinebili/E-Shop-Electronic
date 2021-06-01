#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include<sstream>
#include "Guest.h";
#include"Admin.h";
#include "Notebook.h";
#include"Motherboard.h";
#include "Phone.h";
#include"Catagory.h";
#include"Equipment.h";
#include "Memory.h";
using namespace std;

template<typename T>
class DbSet {
		list<T> items;
public:
	DbSet() = default;
	
 
	list <T> GetItems()const {
		return items;
	}
	void writeUserInfoTofile() {
		ofstream fout("User Info.txt", ios::app);
		if (!fout) {
			throw NullException("File is not found", __LINE__, __FILE__, __TIME__);
		}
		if (fout.is_open()) {
			for (auto& i : items)
			{
				fout << "User usernmae->" << i->GetUsername() << endl;
				fout << "User fullname->" << i->GetFullname() << endl;
				fout << "Connected Data->" << i->GetConnentedDate() << endl;
			}
		}
		else {
			throw InvalidArgumentException("File not open", __LINE__, __FILE__, __TIME__);
		}
		fout.close();
	}
	void add(T item) {
		items.push_back(item);
		writeUserInfoTofile();
	}
	void showGuests() {
		for (auto& i : items)
		{
			i->Show();
		}
	}
};

class Stock {
	list<Equipment*>equipments;
	list<Catagory*>catagories;
	list<Equipment*>cart;
public:
	list<Equipment*>GetEquipments()const{
		return equipments;
	}
	Stock() = default;
	
	void writeUpdateProductToFile(int id){
		ofstream fout("Update Product.txt", ios::app);
		if (!fout) {
			throw NullException("File is not found", __LINE__, __FILE__, __TIME__);
		}
		if (fout.is_open()) {
			fout << "Product name->" << getProductById(id)->GetName() << endl;
			fout << "Product Model->" << getProductById(id)->GetModel() << endl;
			fout << "Product ID->" << getProductById(id)->GetProductID() << endl;
			fout << "Product Price->" << getProductById(id)->GetPrice() << endl;
			fout << "Product Quantity->" << getProductById(id)->GetQuantity() << endl;
		}
		else {
			throw InvalidArgumentException("File not open", __LINE__, __FILE__, __TIME__);
		}
		fout.close();
	}

	Equipment* getProductById(size_t id) {
		for (auto& i : equipments)
		{
			if (id == i->GetProductID()) return i;
		}
	}
	void addEquipment(Equipment* equipment) {
		equipments.push_back(equipment);
	}
	void addNewEquipment(Equipment* equipment) {
		cin >> *equipment;
		equipments.push_back(equipment);
	}
	void addCatagories(Catagory* catagory) {
		catagories.push_back(catagory);
	}
	void updateProductbyId(int id) {
		cin >> *getProductById(id);
		writeUpdateProductToFile(id);
	}
	
	bool isExistsItems(const size_t id) {
		if (id < 0) {
			throw InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__, __TIME__);
		}
		for (auto& item : equipments)
		{
			if (id == item->GetProductID()) return true;
		}
		return false;
	}
	void deleteByProductId(const size_t& id) {
		if (id < 0) {
			throw InvalidArgumentException("Id smaller than 0!", __LINE__, __FILE__, __TIME__);
		}
		else if (isExistsItems(id)) {
			auto itr = equipments.begin();
			advance(itr, id - 1);
			equipments.erase(itr);
		}
		else throw InvalidArgumentException("There is no product in this id!", __LINE__, __FILE__, __TIME__);
	}
	void ShowAllProductInCatagory() {
		for (auto& catagory : catagories)
		{
			cout << "\n\n----------------" << catagory->GetName() << " INFO ------------------" << endl;
			for (auto& i : equipments)
			{
			   if (catagory->GetId() == i->GetCatagoryId()) {
				  
                 i->ShowProduct();
			   }
			}
		}
	}
	void Equipmentshow() {
		for (auto& i : equipments)
		{
			i->EquipmentShow();
			cout << endl;
		}
	}
	void ShowProducts() {
		for (auto& i : equipments)
		{
		   i->ShowProduct();
		   cout << endl;
		}
	}
	
	void addCart(const int productid) {
		cart.push_back(getProductById(productid));
	}
	void deleteByProductCartId(const size_t& cartid) {
		if (cartid <= cart.size()) {
			auto itr = cart.begin();
			advance(itr, cartid - 1);
			cart.erase(itr);
		}
	}
	void showCart() {
		for (int i = 0; i < cart.size(); i++)
		{
			for (auto& c : cart)
			{
				cout << "Cart Product id->" << ++i << endl;
				c->EquipmentShow();
				cout << endl;
			}
		}

	}
	void showCatagory() {
		for (auto& i : catagories)
		{
			i->CatagoryInfo();
			cout << endl;
		}
	}
};

class Database {
public:
	Stock stockDb;
	DbSet<Guest*> guests;

	Database() :stockDb(), guests() {};
	
	Database( Stock stockDb, DbSet<Guest*> guests)
	{
		this->stockDb = stockDb;
		this->guests = guests;
	}
	
};
