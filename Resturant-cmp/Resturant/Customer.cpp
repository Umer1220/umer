#include "Customer.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

Customer::Customer(){
}

Customer::Customer(string Name = "Dummy", string number = "03000000000", int id = 0, int bill = 0): Person(Name), Contact(number), ID(id), Bill(bill){
	
}

void Customer::setID(int id){
	ID = id;	
}

void Customer::setBil(int bill){
	Bill = bill;	
}

void Customer::setContact(string Name){
		name = Name;
}

int Customer::getID(){
	return ID;	
}

int Customer::getBill(){
	return Bill;
}

string Customer::getContact(){
	return Contact;
}

void Customer::addDish(Dish dummy){
	BoughtDish.push_back(dummy);
}






