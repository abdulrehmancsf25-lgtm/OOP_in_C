#pragma once
#include"CharString.h" //comp
#include"Address.h"  // comp
#include"Project.h"  // ass
class Department; // ass
class Employee {
	int ID;
	CharString name;
	Address permanantAddress;
	bool assignedToDept;
	Project* project[3];
	int projectCount;
	float salary;
	Department* dept;

public:
	Employee(int, CharString, Address);
	int getID();
	float getSalary()const; // getter
	void SetSalary(float); // setter 
	void displayEmployeeInfo();
	bool AddProject(Project*);
	bool RemoveProject(int);
	void displayAllProjects();
	void SetAssignedToDept(bool);
	bool SetDepartment(Department* d);

};