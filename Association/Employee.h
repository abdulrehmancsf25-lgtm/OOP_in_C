#pragma once
#include "Computer.h"
#include<iostream>
using namespace std;
class Employee {
public:
	string name;
	inline static int cnt = 0;
	const int ID;
	Computer* computer;

	Employee();
	Employee(string , Computer* );

	
	

};