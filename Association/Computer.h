#pragma once
#include<string>
#include<iostream>
using namespace std;

class Employee;

class Computer {
public:
	string model;
	Employee* employee;

	Computer(string , Employee* );

	Computer();
		
	
};