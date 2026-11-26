#pragma once
#include"Employee.h"
#include"Project.h"
#include"Department.h"
#include"CharString.h"
#include"Address.h"
class Company {
	int employeeCount;
	Employee* employee[500]; // comp
	int deptCount;
	Department* department[20]; // comp 
	int projectCount;
	Project* project[50]; //comp

public:
	Company();
	~Company();
	void AddEmployee(); 
	void AddDepaertment();
	void AddProject();
	void AssignProjectToEmployee(int, int);
	void AssignEmployeeToDepartment(int, int);
	void displayProjects();
	void displayEmployees();
	void displayDepartments();
	void removeProjectFromEmployee(int , int );
	void removeEmployeeFromDepartment(int ,int);

};