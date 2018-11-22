#include "Dish.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <iomanip>
typedef std::vector<Dish> vec_dish;
using namespace std;

Dish::Dish(string Name="NULL", string dishtype = "Null", int Rate=0, int Stock=0):name(Name), Dish_Type(dishtype), rate(Rate), stock(Stock){

}

Dish::Dish():name("NULL"), rate(0), stock(0){
}

string Dish::getName(){
	return name;
}

int Dish::getRate(){
	return rate;
}

int Dish::getStock(){
	return stock;
}

void Dish::setName(string Name){
	name = Name;
}

void Dish::setRate(int Rate){
	rate = Rate;
}

void Dish::setStock(int Stock){
	stock = Stock;
}


string Dish::getDishType(){
	return Dish_Type;
}

void Dish::setDishType(string dishtype){
	Dish_Type = dishtype;
}

void Dish::Display(int i , char a){
	switch(a){
		case 'M':
			cout << i+1 << ") ";
			cout.width(10); 
			cout << left << getName() << "\t";
			cout.width(10);
			cout << left << Dish_Type << "\t";
			cout << getRate() << endl;
			break;
		
		case 'A':
			cout << i+1 << ") ";
			cout.width(10); 
			cout << left << getName() << "\t";
			cout.width(10);
			cout << left << Dish_Type << "\t";
			cout.width(5);
			cout << left << getRate() << "\t";
			cout.width(5);
			cout << left << getStock()<< endl;
			break;	
	}
}

















