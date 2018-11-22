#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"

class Admin : public Person
{
	public:
		Admin();
		Admin(std::string,std::string);
		void setPassword(std::string);
		std::string getPassword();
		void Display();
		void setadmin(std::string,std::string);
	protected:
		std::string Password;
};

#endif
