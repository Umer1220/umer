#ifndef PERSON_H
#define PERSON_H
#include<string>
#include<cstring>

class Person
{
	public:
		Person();
		Person(std::string);
		void setName(std::string);
		std::string getName();
	protected:
		std::string name;
};

#endif
