#include "Employee.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

typedef std::vector<Employee> Vec_Emp;

using namespace std;

Employee::Employee(){
}

Employee::Employee(std::string Name = "Dummy",int id = 0 ,int Salary =10000):
	Person(Name), ID(id), salary(Salary)
{}

void Employee::setemp(std::string Name,int id, int Salary){
	name = Name;
	ID = id;
	salary = Salary;
}

void Employee::setID(int id){
	ID = id;
}

int Employee::getID(){
	return ID;
}

void Employee::setSalary(int Salary){
	salary = Salary;
}

int Employee::getSalary(){
	return salary;
}

void Employee::Display(int i){
	cout << i+1 << ") ";
	cout.width(15);
	cout << left << name << "\t"; 
	cout.width(3); 
	cout << left << ID  << "\t";
	cout.width(6);
	cout << left << salary << endl;
}








