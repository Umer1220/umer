#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Dish.h"
#include <string>
#include <cstring>
#include <vector>


class Customer : public Person
{
	public:
		Customer();
		Customer(std::string, std::string, int, int);
		void setID(int);
		void setBil(int);
		void setContact(std::string);
		int getID();
		int getBill();
		std::string getContact();
		void addDish(Dish);
		std::string Contact;
		int ID;
		int Bill;
		std::vector<Dish> BoughtDish;
};

#endif
