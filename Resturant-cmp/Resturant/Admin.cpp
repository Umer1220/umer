#include "Admin.h"
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

Admin::Admin(){
}

Admin::Admin(string Name="NULL", string password = "No password"):Password(password),Person(Name){
	
}

void Admin::setadmin(string NAME, string passcode){
	name = NAME;
	Password = passcode;
}
void Admin::Display(){
	cout << "NAME: " << name << endl;
	cout << "Password: " << Password << endl;	
}

void Admin::setPassword(string passcode){
	Password = passcode;
}

string Admin::getPassword(){
	return Password;
}
