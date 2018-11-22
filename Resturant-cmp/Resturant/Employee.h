#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Person.h"
#include <vector>


class Employee : public Person
{
	public:
		Employee();
		Employee(std::string,int,int);
		void setemp(std::string,int, int);
		void setID(int);
		int getID();
		void setSalary(int);
		int getSalary(); 
		void Display(int);
		
	private:
		int ID;
		int salary;

};

#endif
