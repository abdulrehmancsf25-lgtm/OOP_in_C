#pragma once
#include"CharString.h" // comp
#include"Project.h" // comp
#include"Employee.h" // agg
class Department {
	int ID;
	CharString name;
	Employee* employee[50];
	int employeeCount;
public:
	Department(int, CharString);
	void displayDeptInfo();
	bool AddEmployee(Employee*);
	bool RemoveEmployee(int);
	void DisplayAllEmployee();
	int getID() const;
};
