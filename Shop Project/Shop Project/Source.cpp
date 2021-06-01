#include<iostream>
#include<string>
#include<conio.h>
#include<iomanip>
#include<Windows.h>
#include"Database.h";
#include"SourceFunctions.h";
using namespace std;
class OperationSystem {
	OperationSystem() {}
public:
	static void controlPC();
};
void OperationSystem::controlPC() {
	ProductinDatabase();
	CatagoryinDatabase();
	GuestsinDatabase();
	int Set[] = { 7,7,7};
	int counter = 2;
	char key;
	try
	{
	   FirstDisplay();
	}
	catch (InvalidArgumentException ex)
	{
		ex.PrintMsg();
	}
	catch (DatabaseException ex)
	{
		ex.PrintMsg();
	}
	catch (NullException ex)
	{
		ex.PrintMsg();
	}
}
int main() {
	OperationSystem::controlPC();
}