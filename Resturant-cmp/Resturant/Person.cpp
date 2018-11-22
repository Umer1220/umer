#include "Person.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Person::Person(): name("NULL"){ 
	
}

Person::Person(string Name): name(Name){ 
	
}

void Person::setName(string Name){
	name = Name;		
}

string Person::getName(){
	return name;		
}

