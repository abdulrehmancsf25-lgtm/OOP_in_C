#include "Employee.h"
#include<string>
Employee::Employee() :ID(++cnt) {
	this->name = "";
	this ->computer = NULL;
}

Employee::Employee(string name, Computer* c):ID(++cnt) {
	this->name = name;
	this->computer = c;
}