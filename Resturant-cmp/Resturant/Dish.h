#ifndef DISH_H
#define DISH_H
#include <cstring>
#include <string>
#include <vector>

class Dish
{
	public:
		Dish();
		Dish(std::string, std::string, int, int);
		void setName(std::string);
		void setRate(int);
		void setStock(int);
		std::string getName();
		int getRate();
		int getStock();
		std::string getDishType();
		void setDishType(std::string);
		void Display(int , char);
	private:
		std::string name;
		int rate;
		int stock;
		std::string Dish_Type;
};

#endif
