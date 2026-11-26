#pragma once
#include"CharString.h"
class Employee;

class Project {
	int ID;
	CharString projectDescription;
	int employeeCount;
	Employee* employee[10];
public:
	Project(int, CharString);
	void displayProjectInfo();
	void DecEmployeeCount();
	void IncEmployeeCount();
	int getID();
	bool AssignToEmployee(Employee*);
	void DisplayAllAssignedEmployees();
};