#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
#include "Dish.h"
#include "Employee.h"
#include "Resturant.h"
#include "Customer.h"


typedef std::vector<Employee> Vec_Emp;
typedef std::vector<Dish> Vec_Dish;

using namespace std;

bool Resturant::giveemp(string name,int id){
	Vec_Emp::iterator it = Employees.begin();
	for(int i=0; i<Employees.size(); i++){
		if(it->getName() == name && it->getID() == id){
			return true;
		}
		it++;
	}
}

void Resturant::DisplayVec_boughtdish(char a){
	switch(a){
		case 'M' :
		{
			Vec_Dish::iterator IT;
   			int I=0;
			for (IT = customer.BoughtDish.begin(); IT != customer.BoughtDish.end(); ++IT) {
    		    IT->Display(I , 'M');
   				I++;
			}
			break;
		}
		
		case 'A' :
		{
			Vec_Dish::iterator it;
   			int i=0;
			for (it = customer.BoughtDish.begin(); it != customer.BoughtDish.end(); ++it) {
   			    it->Display(i ,'A');
   				i++;
			}
			break;
		}
	}		
}

std::string Resturant::adminpassword(){
	return admin.getPassword();
} 

void Resturant::setadmin(std::string name, std::string Password){
		admin.setName(name);
		admin.setPassword(Password);
}

void Resturant::displayadmin(){
	return admin.Display();
}	
		
Resturant::Resturant()
{
}

Vec_Emp Resturant::EmpFileRead(ifstream& file)
{
		int totalEmployees;
		file >> totalEmployees; 
		Vec_Emp myEmployees;
		for(int i=0; i<=totalEmployees; i++){
			int ID, Salary;
			char a;
			string name;  
			file >> ID;
			file >> Salary;
			getline(file,name);
		//	cout << ID << name << Salary << "\n"; 
			Employee dummy(name,ID,Salary);
			myEmployees.push_back(dummy);
		}		
    	return myEmployees;
}

void Resturant::DisplayVec_Emp()
{
	
	Vec_Emp::iterator it = Employees.begin();
	for (int i=0; i<Employees.size(); i++){
        it->Display(i);
   		++it;
	}
}

Vec_Dish Resturant::DishFileRead(ifstream& file)
{
			int totaldish;
			file >> totaldish;
			Vec_Dish Dishes;
			for(int i=0; i<totaldish; i++){
				int Rate, Stock;
				string name, type;
				file >> Rate;
				file >> Stock;
				getline(file, name);
				getline(file, type);
				Dish dummy(name, type, Rate, Stock);
				Dishes.push_back(dummy);
			}
			return Dishes;
}

void Resturant::DisplayVec_Dish(char x)
{
	switch(x){
		case 'M' :
		{
			Vec_Dish::iterator IT;
   			int I=0;
			for (IT = Dishes.begin(); IT != Dishes.end(); ++IT) {
    		    IT->Display(I , 'M');
   				I++;
			}
			break;
		}
		
		case 'A' :
		{
			Vec_Dish::iterator it;
   			int i=0;
			for (it = Dishes.begin(); it != Dishes.end(); ++it) {
   			    it->Display(i ,'A');
   				i++;
			}
			break;
		}
	}	
	
}

void Resturant::DisplayVec_Sold(char x)
{	
		Vec_Dish::iterator it;
 		int i=0;
		for (it = Sold.begin(); it != Sold.end(); ++it) {
			it->Display(i, 'A');
			i++;
		}
		
}

Resturant::Resturant(ifstream& EmpFile, ifstream& dishes, ifstream& SoldDishes, ifstream& Acc_file)
{
	Employees = EmpFileRead(EmpFile);
	Dishes = DishFileRead(dishes);
	Sold = DishFileRead(dishes);
	
	string  name, passcode;
	getline(Acc_file, name);
	getline(Acc_file, passcode);
	admin.setadmin(name,passcode);
	
	Acc_file >> total_sail;	
}

int Resturant::getbill(){
	return customer.Bill;
}

int Resturant::gettotal_sail(){
	return total_sail;
}

void Resturant::save(){
	ofstream SoldFile;
	ofstream DishesFile;
	ofstream EmployeesFile;
	ofstream acc_file;
	
	SoldFile.open("SoldDishes.txt" );
	DishesFile.open("Dishes.txt" );
	EmployeesFile.open("Employees.txt");
	acc_file.open("AccountFile.txt");
	
	SoldFile << Sold.size() << "\n";
	DishesFile << Dishes.size() << "\n";
	EmployeesFile <<  Employees.size() << "\n";
	
	for(Vec_Emp::iterator emp= Employees.begin(); emp != Employees.end(); ++emp){
		EmployeesFile << emp->getID() << " ";
		EmployeesFile << emp->getSalary() << "\n";
		EmployeesFile << emp->getName() << "\n"; 
	}

	for(Vec_Dish::iterator dish= Dishes.begin(); dish != Dishes.end(); ++dish){
		DishesFile << dish->getRate() << " ";
		DishesFile << dish->getStock() << " ";
		DishesFile << dish->getName() << "\n";
		DishesFile << dish->getDishType() << "\n";
	}
	
	for(Vec_Dish::iterator dish= Sold.begin(); dish != Sold.end(); ++dish){
		SoldFile << dish->getRate() << " ";
		SoldFile << dish->getStock() << " ";
		SoldFile << dish->getName() << "\n";
		SoldFile << dish->getDishType() << "\n";
	}
	
	acc_file << admin.getName() << "\n";
	acc_file << admin.getPassword() << "\n";
	acc_file << total_sail;
	
	
	SoldFile.close();
	DishesFile.close();
	EmployeesFile.close();
	acc_file.close();
}

Resturant::~Resturant(){
	Resturant::save();
}

std::string Resturant::adminName(){
	return admin.getName();
}

void Resturant::addDish(){
	string Name,Type;
	int type, Rate, Stock, i=0;
	
	cout << "Enter Dish Name:\n";
	getchar();
	getline(cin , Name);
	cout << "Enter Dish Type:\n";
	cout << "1-Main Course\n2-Appetizer\n3-Desert\n4-Drink\n";
	
	do{
	
		if(i>0){
			cout << "Enter Correct Type Of Dish:\n";
		}
	
		cin >> type;
		i++;
	}
	while(type >4 && type <1);
	
	switch (type){
		case 1:
			Type = "Main Course";
			break;
		
		case 2:
			Type = "Appetizer";
			break;
			
		case 3:	
			Type = "Desert";
			break;
		case 4:
			Type = "Drink";
			break;	
	}
	
	cout << "Enter Rate:\n";
	cin  >>  Rate;
	cout << "Enter Stock\n";
	cin >> Stock;
	
	Dish dummy(Name,Type,Rate,Stock);
	
	Dishes.push_back(dummy);
}

void Resturant::eraseDish(int i){
	Dishes.erase(Dishes.begin()+i);
}

void Resturant::soldDish(int i, int Quantity){
	while(i>Dishes.size()){
		cout << "Enter Serial number of The Dish\nYou Want to Buy:\n"; 
		cin >> i;
	}
	Vec_Dish::iterator it = Dishes.begin()+i;
		
	while(it->getStock()<Quantity || i>Dishes.size()){
		cout << "Enter Quantity do You Want to buy:";
		cin >> Quantity;
	}
	
	if(it->getStock()-Quantity == 0){
		eraseDish(i);
	}
	else{
		it->setStock(it->getStock()-Quantity);
	}
	Dish dummy(it->getName(), it->getDishType(), it->getRate(), Quantity);
	Sold.push_back(dummy);
	customer.Bill += (Quantity * it->getRate());
	customer.BoughtDish.push_back(dummy);
}

void Resturant::eraseEmployee(int i){
	Employees.erase(Employees.begin() + i);
}

void Resturant::addEmployee(){
		string Name;
		int ID , Salary;
		
		cout << "Enter Name of Employee:\n";
		getchar();
		getline(cin , Name);

		vector<Employee>::iterator it;
		ID = Employees.size() + 1;

		cout << "Enter Employee`s Salary:\n";
		cin >> Salary;
		
		Employee dummy(Name,ID, Salary);
		Employees.push_back(dummy);
}













