#pragma once
#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include"Database.h";

using namespace std;

Database* db = new Database();

void mySetColor(int fg, int bg) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

void ControlMenu(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void FirstDisplay();

void GuestDisplay();

void Createadmin() {
	string stringu;
	string stringp;
	cout << "\n\n\n\n\n\n" << setw(55) << "Enter username->";
	getline(cin, stringu);
	cout << setw(55) << "Enter Password->";
	getline(cin, stringp);

	Admin* admin = new Admin(stringu, stringp);

}

void ExitBackGuestDisplay() {
	int Set[] = { 7,7 };
	int counter = 1;
	char key;
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "<X>Exit" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "<-Back" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 2)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 1)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		if (key == '\r') {
			if (counter == 0) {
				system("cls");
				mySetColor(7, 0);
				exit(0);
			}
			if (counter == 1) {
				mySetColor(7, 0);
				GuestDisplay();
				break;
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
	}
}

void GuestSignUp() {
	system("Color 0E");
	cout <<"\n\n"<<setw(75) << "<<<<<<<<<<<<<<<<<< Register >>>>>>>>>>>>>>>>>>>" << endl;
	string username, fullname, password;
	cout << "\n\n\n\n" << setw(58) << "Enter username->";
	getline(cin, username);
	cout << setw(58) << "Enter Fullname->";
	getline(cin, fullname);
	cout <<  setw(58) << "Enter Password->";
	getline(cin, password);
	mySetColor(7, 0);
	for (auto& i : db->guests.GetItems())
	{
		if (i->GetUsername() == username) {
			throw DatabaseException("This username cannot be used", __LINE__, __FILE__, __TIME__);
		}
	}
	Guest* newguest = new Guest(username,password,fullname, __TIME__);
	db->guests.add(newguest);

	Sleep(1000);
	cout << "\n\nSign Up Is Successfully" << endl;

	int Set[] = { 7,7 };
	int counter = 1;
	char key;
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "<-Back" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "<X> Exit" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 2)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 1)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		if (key == '\r') {
			if (counter == 0) {
				system("cls");
				mySetColor(7, 0);
				FirstDisplay();
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				exit(0);
				break;
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
	}
}

void GuestSignIn() {
	system("Color 0B");
	cout <<"\n\n"<<setw(75) << "<<<<<<<<<<<<<<<<<<< Log In >>>>>>>>>>>>>>>>>>>" << endl;
	string username, password;
	cout << "\n\n\n\n" << setw(62) << "Enter username->";
	getline(cin, username);
	cout << setw(62) << "Enter Password->";
	getline(cin, password);
	mySetColor(7, 0);
	for (auto& i : db->guests.GetItems())
	{
		if (i->GetUsername() == username && i->GetPassword() == password) {
			Sleep(1000);
			cout << "User Sign In" << endl;
			return;
		}
		else if (i->GetUsername() == username && i->GetPassword() != password) {
			throw DatabaseException("Password is wrong", __LINE__, __FILE__, __TIME__);
		}
	}
	throw DatabaseException("This user is not available", __LINE__, __FILE__, __TIME__);
}

void CartMenu();

void DeleteProductCart() {
	system("cls");
	system("Color 0A");
	db->stockDb.showCart();
	cout << "\n\n";
	int id;
	char contexit;
	mySetColor(7, 0);
	while (true)
	{
		cout << "Enter delete product Cart id->";
		cin >> id;
		db->stockDb.deleteByProductCartId(id);
		cout << "Continue Delete or exit (Continue(c) Exit(e) )->";
		cin >> contexit;
		if (contexit == 'c') {
			DeleteProductCart();
		}
		if (contexit == 'e') {
			break;
		}
	}
	system("cls");
	CartMenu();
}

void addCartbuyProduct() {
	system("cls");
	system("Color 0D");
	db->stockDb.Equipmentshow();
	int id, quantity;
	char contexit;
	int temp;
	mySetColor(7, 0);
	while (true)
	{

		cout << "Enter Buy Product id->";
		cin >> id;
		db->stockDb.addCart(id);
		
		cout << "Continue Add or exit (Continue(c) Exit(e) )->";
		cin >> contexit;
		if (contexit == 'c') {
			addCartbuyProduct();
		}
		if (contexit == 'e') {
			break;
		}
	}
	GuestDisplay();

}

void buyProductCart() {
	system("cls");
	cout << "\n\n\n";
	system("Color 0B");
	db->stockDb.showCart();
	cout << "\n\n\n";
	int id, quantity, catagoryid;
	char contexit;
	while (true)
	{
		cout << "The ID of the PRODUCT you entered the quantity->";
		cin >> id;
		cout << "The Id of the CART you entered the quantity->";
		cin >> catagoryid;
		cout << "Enter quantity->";
		cin >> quantity;
		int  temp;
		temp = db->stockDb.getProductById(id)->GetQuantity() - quantity;
		if (temp == 0) {
			db->stockDb.deleteByProductCartId(catagoryid);
			db->stockDb.deleteByProductId(id);
		}
		else if (temp != 0) {
		 
			db->stockDb.getProductById(id)->SetQuantity(temp);
		}
		cout << "Continue Add or exit (Continue(c) Exit(e) )->";
		cin >> contexit;
		if (contexit == 'c') {
			buyProductCart();
		}
		if (contexit == 'e') {
			break;
		}
	}
	string country, city, phonenumber, postaladdress, name;
	cout << "\n\n\n";
	cout << "Enter Name->";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Country->";
	getline(cin, country);
	cout << "Enter City->";
	getline(cin, city);
	cout << "Enter Phone Number->";
	getline(cin, phonenumber);
	cout << "Enter Postal Adress->";
	getline(cin, postaladdress);

	cout << "\n\n\n";
	Sleep(1000);
	cout << "The order was confirmed  (* _ *)" << endl;

	int Set[] = { 7,7 };
	int counter = 1;
	char key;
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "<X>Exit" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "<-Back" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 2)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 1)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		if (key == '\r') {
			if (counter == 0) {
				system("cls");
				mySetColor(7, 0);
				exit(0);
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				CartMenu();
				break;
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
	}
	
	
}

void CartMenu() {
	system("Color 0E");
	cout << "\n\n" << setw(77) << "<<<<<<<<<<<<<<<<<< Cart Menu >>>>>>>>>>>>>>>>>>>" << endl;
	int Set[] = { 7,7,7,7 };
	int counter = 3;
	char key;
	for (int i = 0;;) {
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "\n\n\n\n\n\n" << setw(50) << "<-Back" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "\n\n\n\n\n\n\n" << setw(78) << "Buy the products add on the card" << endl;
		ControlMenu(0, 2);
		mySetColor(Set[2], 0);
		cout << "\n\n\n\n\n\n\n" << setw(70) << "Delete Product from Cart" << endl;
		ControlMenu(0, 3);
		mySetColor(Set[3], 0);
		cout << "\n\n\n\n\n\n\n\n" << setw(52) << "<X> Exit" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 4)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 2)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;

		if (key == '\r') {
			if (counter == 0) {
				mySetColor(7, 0);
				system("cls");
				GuestDisplay();
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				buyProductCart();
				break;
			}
			if (counter == 2) {
				mySetColor(7, 0);
				system("cls");
				DeleteProductCart();
				break;
			}
			if (counter == 3) {
				mySetColor(7, 0);
				system("cls");
				exit(0);
			}

		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
		if (counter == 2) {
			mySetColor(Set[2] = 12, 0);
		}
		if (counter == 3) {
			mySetColor(Set[3] = 12, 0);
		}

	}

}


void GuestDisplay() {
	system("cls");
	system("Color 0A");
	cout <<"\n\n"<<setw(73) << "<<<<<<<<<<<<<<<<< Guest Panel >>>>>>>>>>>>>>>>>" << endl;
	cout << "\n\n\n\n\n\n\n\n";
	mySetColor(4, 0);
	cout << "<<  PRODUCTS  >>" << endl << endl;
	db->stockDb.Equipmentshow();
	int Set[] = { 7,7,7,7,7};
	int counter = 4;
	char key;
	for (int i = 0;;) {
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "\n\n\n\n"<< setw(68) << "<-Back" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "\n\n\n\n" << setw(100) << "Add the purchased products to the Cart" << endl;
		ControlMenu(0, 2);
		mySetColor(Set[2], 0);
		cout << "\n\n\n\n" << setw(81) << "Show Product Detail" << endl;
		ControlMenu(0, 3);
		mySetColor(Set[3], 0);
		cout << "\n\n\n\n" << setw(66) << "Cart" << endl;
		ControlMenu(0, 4);
		mySetColor(Set[4], 0);
		cout << "\n\n\n\n" << setw(70) << "<X> Exit" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 5)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 3)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;

		if (key == '\r') {
			if (counter == 0) {
				mySetColor(7, 0);
				system("cls");
				FirstDisplay();
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				addCartbuyProduct();
				break;
			}
			if (counter == 2) {
				mySetColor(7, 0);
				system("cls");
				cout << "\n";
				system("Color 0B");
				db->stockDb.ShowAllProductInCatagory();
				ExitBackGuestDisplay();
				break;
			}
			if (counter == 3) {
				mySetColor(7, 0);
				system("cls");
				CartMenu();
				break;
			}
			if (counter == 4) {
				mySetColor(7, 0);
				system("cls");
				exit(0);
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
		if (counter == 2) {
			mySetColor(Set[2] = 12, 0);
		}
		if (counter == 3) {
			mySetColor(Set[3] = 12, 0);
		}
		if (counter == 4) {
			mySetColor(Set[4] = 12, 0);
		}
	}


}

void AdminDisplay();
void FirstDisplay() {
	int Set[] = { 7,7,7 };
	int counter = 2;
	char key;
                                                                                
    cout<<",------.                 ,--.                                    ,---.                    "<<endl;
    cout<<"|  .---' ,-----.  ,---.  |  ,---.   ,---.   ,---.   ,---.       /  O  \\   ,---.   ,---.   "<<endl;
    cout<<"|  `--,  '-----' (  .-'  |  .-.  | | .-. | | .-. | | .-. |     |  .-.  | | .-. | | .-. |  "<<endl;
    cout<<"|  `---.         .-'  `) |  | |  | ' '-' ' | '-' ' | '-' '     |  | |  | | '-' ' | '-' '  "<<endl;
    cout<<"`------'         `----'  `--' `--'  `---'  |  |-'  |  |-'      `--' `--' |  |-'  |  |-'   "<<endl;
    cout<<"                                           `--'    `--'                  `--'    `--'     "<<endl;
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "\n\n\n\n\n\n\n\n" << setw(50) << "[1]ADMIN" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "\n\n\n\n\n\n\n\n" << setw(58) << "[2]GUEST SIGN UP" << endl;
		ControlMenu(0, 2);
		mySetColor(Set[2], 0);
		cout << "\n\n\n\n\n\n\n\n" << setw(58) << "[3]GUEST SIGN IN" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 3)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 2)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		if (key == '\r') {
			if (counter == 0) {
				system("cls");
				mySetColor(7, 0);
				Createadmin();
				system("cls");
				AdminDisplay();
				break;
			}
			if (counter == 1) {
				system("cls");
				mySetColor(7, 0);
				GuestSignUp();
				break;
			}
			if (counter == 2) {
				system("cls");
				mySetColor(7, 0);
				GuestSignIn();
				system("cls");
				GuestDisplay();
				break;
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
		if (counter == 2) {
			mySetColor(Set[2] = 12, 0);
		}
	}
}

void ExitBackAdmin() {
	int Set[] = { 7,7 };
	int counter = 1;
	char key;
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "<-Back" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "<X> Exit" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 2)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 1)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		if (key == '\r') {
			if (counter == 0) {
				system("cls");
				mySetColor(7, 0);
				AdminDisplay();
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				exit(0);
				break;
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
	}
}

void AddProduct();

void UpdateProduct() {
	system("cls");
	mySetColor(2, 0);
	db->stockDb.showCatagory();
	cout << "\n\n";
	mySetColor(11, 0);
	db->stockDb.ShowProducts();
	cout << "\n\n";
	int id;
	char contexit;
	mySetColor(6, 0);
	while (true)
	{
		cout << "Enter Update product id->";
		cin >> id;
		db->stockDb.updateProductbyId(id);
		Sleep(1000);
		cout << "\n\nUpdate is successfully" << endl;
		cout << "Continue Update or exit (Continue(c) Exit(e) )->";
		cin >> contexit;
		if (contexit == 'c') {
			UpdateProduct();
			
		}
		if (contexit == 'e') {
			break;
		}
	}
	system("cls");
	AdminDisplay();
}

void DeleteProduct() {
	system("cls");
	mySetColor(0, 9);
	cout << "\n\n" << "------------ Deleted Product ------------" << endl << endl;
	mySetColor(12, 0);
	db->stockDb.Equipmentshow();
	int id;
	char contexit;
	mySetColor(6, 0);
	while (true)
	{
		cout << "Enter Delete product id->";
		cin >> id;
		db->stockDb.deleteByProductId(id);
		Sleep(1000);
		cout << "\nDelete is successfully" << endl;
		cout << "\nContinue Delete or exit (Continue(c) Exit(e) )->";
		cin >> contexit;
		if (contexit == 'c') {
			DeleteProduct();
		}
		if (contexit == 'e') {
			break;
		}
	}
	system("cls");
	AdminDisplay();
}

void AdminDisplay() {
	int Set[] = { 7,7,7,7,7,7,7};
	int counter = 6;
	char key;
	system("cls");
	system("Color 0D");
	cout <<"\n"<< setw(84) <<"<<<<<<<<<<<<<<<<<<<<<<<<<< Admin Panel >>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "\n\n\n\n\n\n" << setw(49) <<  "<-Back" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "\n\n\n\n\n\n\n" << setw(55) << "Add Product" << endl;
		ControlMenu(0, 2);
		mySetColor(Set[2], 0);
		cout << "\n\n\n\n\n\n\n" << setw(70) << "Show Catagory with Product" << endl;
		ControlMenu(0, 3);
		mySetColor(Set[3], 0);
		cout << "\n\n\n\n\n\n\n" << setw(58) << "Delete product" << endl;
		ControlMenu(0, 4);
		mySetColor(Set[4], 0);
		cout << "\n\n\n\n\n\n\n" << setw(58) << "Update Product" << endl;
		ControlMenu(0, 5);
		mySetColor(Set[5], 0);
		cout << "\n\n\n\n\n\n\n" << setw(55) << "Guests Info" << endl;
		ControlMenu(0, 6);
		mySetColor(Set[6], 0);
		cout << "\n\n\n\n\n\n\n\n" << setw(51) << "<X> Exit" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 7)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 6)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;
		Set[5] = 7;
		Set[6] = 7;
		if (key == '\r') {
			if (counter == 0) {
				mySetColor(7, 0);
				system("cls");
				FirstDisplay();
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				AddProduct();
				ExitBackAdmin();
			}
			if (counter == 2) {
				mySetColor(7, 0);
				system("cls");
				cout << "\n";
				mySetColor(2, 0);
				db->stockDb.ShowAllProductInCatagory();
				ExitBackAdmin();
			}
			if (counter == 3) {
				mySetColor(7, 0);
				system("cls");
				DeleteProduct();
			}
			if (counter == 4) {
				mySetColor(7, 0);
				system("cls");
				UpdateProduct();
			}
			if (counter == 5) {
				mySetColor(7, 0);
				system("cls");
				cout << "\n\n\n";
				mySetColor(9, 0);
				db->guests.showGuests();
				ExitBackAdmin();
			}
			if (counter == 6) {
				mySetColor(7, 0);
				system("cls");
				exit(0);
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
		if (counter == 2) {
			mySetColor(Set[2] = 12, 0);
		}
		if (counter == 3) {
			mySetColor(Set[3] = 12, 0);
		}
		if (counter == 4) {
			mySetColor(Set[4] = 12, 0);
		}
		if (counter == 5) {
			mySetColor(Set[5] = 12, 0);
		}
		if (counter == 6) {
			mySetColor(Set[6] = 12, 0);
		}
	}
}

void ProductinDatabase() {
	Notebook* notebook1 = new Notebook(1,"Notebooks","Acer Nitro 5 Gameing Laptop", 788, "Acer", "Red", "Intel Core i5-9300H Processor"
		, "4.1 GHz", true, 256, "8 GB DDR4",3);
	Notebook* notebook2 = new Notebook(1, "Notebooks", "ASUS F512JA-AS34", 456, "ASUSF", "Black", "Intel Core i3-1005G1",
		"3.4 GHz", true, 128, "DDR4 SDRAM",5);
	Phone* phone1 = new Phone(2,"Phones","Iphone 12 Pro Max", "Apple", "Black", 1824, 128, "12 Mp Ultra", "12 Mp Ultra", "6.1 inches",2);
	Phone* phone2 = new Phone(2,"Phones", "Samsung Galaxy S21", "SAMSUNG", "Phantom Gray", 1235, 256, "64 Mp", "64 Mp", "6.2 inches",4);
	Memory* memory1 = new Memory(3,"Memories","Corsair Vengeance LPX", "16 GB", "16 Gb SDRAM", 102,2);
	Motherboard* motherboard1 = new Motherboard(3,"Motherboards","ASRock H110 Pro", 379.95, 3, 4, "BGA 437", "Micro ATX");

	db->stockDb.addEquipment(notebook1);
	db->stockDb.addEquipment(notebook2);
	db->stockDb.addEquipment(phone1);
	db->stockDb.addEquipment(phone2);
	db->stockDb.addEquipment(memory1);
	db->stockDb.addEquipment(motherboard1);
	
}

void CatagoryinDatabase() {
	Catagory* catagory1 = new Catagory("Computers");//id 1
	Catagory* catagory2 = new Catagory("Electronics");//id 2
	Catagory* catagory3 = new Catagory("Computer Components");//id 3

	
	db->stockDb.addCatagories(catagory1);
	db->stockDb.addCatagories(catagory2);
	db->stockDb.addCatagories(catagory3);
	
}

void GuestsinDatabase() {
	Guest* guest1 = new Guest("Nebi", "Nebi123", "NebiNebili", __TIME__);
	Guest* guest2 = new Guest("Kenan", "Kenan123", "KenanIdayetov", __TIME__);

	db->guests.add(guest1);
	db->guests.add(guest2);
}

void ExitBackAddProduct() {
	int Set[] = { 7,7 };
	int counter = 1;
	char key;
	for (int i = 0;;)
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "<X> Exit" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "<- Back" << endl;
		key = _getch();
		if (key == 72 && (counter >= 1 && counter <= 2)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 1)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		if (key == '\r') {
			if (counter == 0) {
				system("cls");
				mySetColor(7, 0);
				exit(0);
			}
			if (counter == 1) {
				mySetColor(7, 0);
				AddProduct();
				break;
			}
		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
	}
}

void AddProduct() {
    system("cls");
	mySetColor(9, 0);
	cout << "\n" << setw(80) <<"<<<<<<<<<<<<<<<<<<<<<<<<< Add Product >>>>>>>>>>>>>>>>>>>>>>" << endl;
	int Set[] = { 7,7,7,7,7,7 };
	int counter = 5;
	char key;
	int id;
	for (int i = 0;; )
	{
		ControlMenu(0, 0);
		mySetColor(Set[0], 0);
		cout << "\n\n\n\n\n\n" << setw(50) << "<-Back" << endl;
		ControlMenu(0, 1);
		mySetColor(Set[1], 0);
		cout << "\n\n\n\n\n\n\n" << setw(52) << "[1]Phone" << endl;
		ControlMenu(0, 2);
		mySetColor(Set[2], 0);
		cout << "\n\n\n\n\n\n\n" << setw(53) << "[2]Memory" << endl;
		ControlMenu(0, 3);
		mySetColor(Set[3], 0);
		cout << "\n\n\n\n\n\n\n" << setw(58) << "[3]Motherboard" << endl;
		ControlMenu(0, 4);
		mySetColor(Set[4], 0);
		cout << "\n\n\n\n\n\n\n" << setw(55) << "[4]Notebook" << endl;
		ControlMenu(0, 5);
		mySetColor(Set[5], 0);
		cout << "\n\n\n\n\n\n\n\n" << setw(52) <<"<X> Exit" << endl;
		key = _getch();

		if (key == 72 && (counter >= 1 && counter <= 6)) {
			counter--;
		}
		if (key == 80 && (counter >= 0 && counter <= 4)) {
			counter++;
		}
		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;
		Set[4] = 7;
		Set[5] = 7;
		if (key == '\r') {
			if (counter == 0) {
				mySetColor(7, 0);
				system("cls");
				AdminDisplay();
				
			}
			if (counter == 1) {
				mySetColor(7, 0);
				system("cls");
				Phone* newphone = new Phone();
				mySetColor(6, 0);
				cout << "\n\n\n";
				db->stockDb.showCatagory();
				db->stockDb.addNewEquipment(newphone);
				Sleep(1000);
				mySetColor(7, 0);
				cout << "\nProduct added successfully";
				ExitBackAddProduct();
			}
			if (counter == 2) {
				mySetColor(7, 0);
				system("cls");
				Memory* newmemory = new Memory();
				mySetColor(9, 0);
				cout << "\n\n\n";
				db->stockDb.showCatagory();
				db->stockDb.addNewEquipment(newmemory);
				Sleep(1000);
				mySetColor(7, 0);
				cout << "\nProduct added successfully";
				ExitBackAddProduct();
			}
			if (counter == 3) {
				mySetColor(7, 0);
				system("cls");
				Motherboard* newmotherboard = new Motherboard();
				mySetColor(10, 0);
				cout << "\n\n\n";
				db->stockDb.showCatagory();
				db->stockDb.addNewEquipment(newmotherboard);
				Sleep(1000);
				mySetColor(7, 0);
				cout << "\nProduct added successfully";
				ExitBackAddProduct();
			}
			if (counter == 4) {
				mySetColor(7, 0);
				system("cls");
				Notebook* newnotebook = new Notebook();
				mySetColor(13, 0);
				cout << "\n\n\n";
				db->stockDb.showCatagory();
				db->stockDb.addNewEquipment(newnotebook);
				Sleep(1000);
				mySetColor(7, 0);
				cout << "\nProduct added successfully";
				ExitBackAddProduct();
				
			}
			if (counter == 5) {
				mySetColor(7, 0);
				system("cls");
				exit(0);
			}

		}
		if (counter == 0) {
			mySetColor(Set[0] = 12, 0);
		}
		if (counter == 1) {
			mySetColor(Set[1] = 12, 0);
		}
		if (counter == 2) {
			mySetColor(Set[2] = 12, 0);
		}
		if (counter == 3) {
			mySetColor(Set[3] = 12, 0);
		}
		if (counter == 4) {
			mySetColor(Set[4] = 12, 0);
		}
		if (counter == 5) {
			mySetColor(Set[5] = 12, 0);
		}
	}
}


