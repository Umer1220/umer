#ifndef RESTURANT_H
#define RESTURANT_H
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include "Dish.h"
#include "Employee.h"
#include "Customer.h"
#include "Admin.h"
typedef std::vector<Employee> Vec_Emp;
typedef std::vector<Dish> Vec_Dish;

class Resturant
{
	public:
		friend class Customer;
		void save();
		Resturant();
		bool giveemp(std::string,int);
		Resturant(std::ifstream&, std::ifstream&, std::ifstream&, std::ifstream&);
		void DisplayVec_Emp();
		Vec_Emp EmpFileRead(std::ifstream&);
		Vec_Dish DishFileRead(std::ifstream&);
		void DisplayVec_Sold(char);
		void DisplayVec_Dish(char);
		void DisplayVec_boughtdish(char);
		int gettotal_sail();
		void eraseDish( int i);
		void addDish();
		void soldDish(int, int);
		void eraseEmployee(int);
		void addEmployee();
		~Resturant();
		std::string adminpassword();
		void displayadmin();
		void setadmin(std::string name, std::string Password);
		int getbill(); 
		std::string adminName(); 	
	private:
		Customer customer;
		Admin admin;
		std::vector<Employee> Employees;
		std::vector<Dish> Dishes;
		std::vector<Dish> Sold;	
		int total_sail;
};

#endif
