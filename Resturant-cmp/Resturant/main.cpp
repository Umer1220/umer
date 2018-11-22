#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Employee.h"
#include "Dish.h"
#include "Resturant.h"
#include <stdio.h>
#include <algorithm>
#include <ctime>
#include <string>
#include <cstring>
#include <string.h>
#include <ctype.h>

typedef std::vector<Employee> Vec_Emp;
typedef std::vector<Dish> Vec_Dish;

using namespace std;


int main(){
	ifstream employeesFile;
	employeesFile.open("Employees.txt"); 
	if(!employeesFile.is_open()){
		cout << "Error in opening File\n";
	}
//////////////////////////////////////////////////////////////////////////////////////////////////
	ifstream DishesFile;
	DishesFile.open("Dishes.txt");
	if(!DishesFile.is_open()){
		cout << "Error in opening File\n";
	}
////////////////////////////////////////////////////////////////////////////////////////////////
	ifstream soldDishesFile;
	soldDishesFile.open("SoldDishes.txt");
	if(!soldDishesFile.is_open()){
		cout << "Error in opening File\n";
	}
////////////////////////////////////////////////////////////////////////////////////////////////
	ifstream AccountFile;
	AccountFile.open("AccountFile.txt");
	if(!AccountFile.is_open()){
		cout << "Error in opening File\n";
	}
////////////////////////////////////////////////////////////////////////////////////////////////	
	Resturant My_Resturant(employeesFile,DishesFile,soldDishesFile,AccountFile);
	int a;
	
	do{
		cout << "login" << endl;
		cout << "1-Admin\n2-Employees\n3-Customers\n0-Exit\n";
		cin >> a;
		system("CLS");
		switch(a){
			
			case 1:
			{	string password;
				system("CLS");
				cout << "Enter Password:\n";
				getchar();
				getline(cin, password);
				
				while(password != My_Resturant.adminpassword()){
						cout << "Wrong Password\nTry Again\n";
						getline(cin, password);
				}

				if(password == My_Resturant.adminpassword()){
					system("CLS");
					cout << "Welcome to ASH\n";
					cout << My_Resturant.adminName() << endl;
					system("pause");
					int b = 1;
					system("CLS");
					
					while(b!=0){
						system("CLS");
						cout << "1-Employees Setting\n2-Admin Options\n0-Exit\n";
						cin >> b;
			
						switch(b)
						{
							case 1:
							{
								
								int c = 1;
								while( c != 0){
									cout << "1-Display Employees\n2-Add Employees\n3-Delete Employee\n0-Exit\n";
									cin >> c;
									system("CLS");
									switch(c)
									{
										case 1:
											My_Resturant.DisplayVec_Emp();
										break;
										
										case 2:
											My_Resturant.addEmployee();
											My_Resturant.save();
										break;
										
										case 3:
											int d;
											cout << "Enter serial number to Delete:";
											cin >> d;
											My_Resturant.eraseEmployee(d-1);
											My_Resturant.save();
										break;
									}
							}
							break;
	
	
							}
							
							case 2:
								int e= 1;
								while( e!= 0 ){
										
									cout << "1-Detail\n2-Edit\n0-Exit\n";
									cin >> e;
									system("CLS");
									switch(e){
										case 1:
											My_Resturant.displayadmin();
										break;
										
										case 2:
											string passcode , name;
											cout << "Enter New Name:\n";
											getchar();
											getline(cin, name);
											cout << "Enter New Password\n";
											getline(cin,passcode);
											My_Resturant.setadmin(name,passcode);
											My_Resturant.save();
											break;	
									}
								}
							
							break;
						}
					}
		
				}
			break;
			}
			
			case 2:
			{
				string name;
				int id;
				cout << "Enter Your Name:\n";
				getchar();
				getline(cin,name);
				cout << "Enter Your ID:\n";
				cin >> id;
				system("CLS");
				int f=1;
				if(My_Resturant.giveemp(name,id)){
			
					while(f!=0){
						cout << "1-Display Menu\n2-Add Dish\n3-Delete Dish\n0-Exit\n";
						cin >> f;
						system("CLS");
						switch(f){
							
							case 1:
							{
								My_Resturant.DisplayVec_Dish('A');	
							}
							break;
							
							case 2:
							{
								My_Resturant.addDish();
								My_Resturant.save();
							}
							break;
							
							case 3:
							{
								int i;
								cout << "Enter Serail Number of Dish in Menu to delete:\n";
								cin >> i;
								My_Resturant.eraseDish(i-1);
								My_Resturant.save();
							}
							break;	
						}
					}
			}
			break;
			}
			break;
			
			case 3:
			{	
				int g=1;
				while(g!=0){
					cout << "1-Display Menu\n2-Buy Dish\n3-Display Bought Dishes\n4-Pay Bill\n0-Exit\n";
					cin >> g;
					system("CLS");
					switch(g){
						case 1:
						{
							My_Resturant.DisplayVec_Dish('M');
						}
						break;
						
						case 2:
						{
							My_Resturant.DisplayVec_Dish('M');
							int i,j;
							cout << "Enter Serial number of The Dish\nYou Want to Buy:\n";
							cin >> i;
							cout << "Enter Quantity to You Want to buy:";
							cin >> j;
							My_Resturant.soldDish(i-1,j);
							My_Resturant.save();
						}
						break;
						
						case 3:
						{
							
							My_Resturant.DisplayVec_boughtdish('M');
							My_Resturant.save();
						}
						break;
						
						case 4:
						{	
							cout << "You Bought:\n";
							My_Resturant.DisplayVec_boughtdish('A');
							cout << "Your Total Bill is :";
							cout << My_Resturant.getbill() << endl;
							cout << "Thanks For Choosing us! " << endl;
							system("Pause");
							g=0;
							system("CLS");
							My_Resturant.save();
						}
						break;
					}
				}
			}
			break;	
		}
		
		
	}while(a!=0);
	employeesFile.close();
	DishesFile.close();
	soldDishesFile.close();
	AccountFile.close();
}
