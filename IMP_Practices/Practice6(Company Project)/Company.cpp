#include"Company.h"
#include<iostream>
using namespace std;
Company::Company() {
	this->employeeCount = this->deptCount = this->projectCount = 0;
	for (int i = 0; i < 500; i++) {
		this->employee[i] = NULL;
		if (i < 50) {
			project[i] = NULL;
			if (i < 20)
				department[i] = NULL;
		}
	}	 
}

Company::~Company() {
	for (int i = 0; i < 500; i++) {
		if(employee[i])
		delete employee[i];
		if (i < 50) {
			if (project[i])
				delete project[i];
			if (i < 20)
				if (department[i])
					delete department[i];
		}
	  }
}


void Company::AddEmployee() {

	if (this->employeeCount < 500) {
		int ID;
		cout << "Enter the ID of employee : ";
		cin >> ID;
		char name[50];
		cout << "Enter Employee Name: ";
		cin.getline(name, 50, '\n');

		int houseNo, streetNo;
		char block;
		char city[50];
		cout << "Enter employee Address details " << endl;
		cout << "Enter street No : ";
		cin >> streetNo;
		cout << "Enter houseNo : ";
		cin >> houseNo;
		cout << "Enter block(e.g. A , B ,Y, Z): ";
		cin >> block;
		cout << "Enter city : ";
		cin.getline(city, 50, '\n');


		this->employee[employeeCount++] = new Employee(ID, CharString(name), Address(houseNo, block, streetNo, CharString(city)));

	}
	else
		cout << "no employee can be added further already have 500 employees" << endl;
}


void Company::AddDepaertment() {
	if (this->deptCount < 20) {
		int ID;
		char deptName[50];
		cout << "Enter department ID : ";
		cin >> ID;
		cout << "Enter department name : ";
		cin.getline(deptName, 50, '\n');
		this->department[deptCount++] = new Department(ID, CharString(deptName));
	}
	else
		cout << "no department can be added further already have 20 departments" << endl;
}

void Company::AddProject() {
	if (this->projectCount < 50) {
		int ID;
		char projDes[500];
		cout << "Enter project ID : ";
		cin >> ID;
		cout << "Enter project description : ";
		cin.getline(projDes, 500, '\n');
		this->project[projectCount++] = new Project(ID, CharString(projDes));
	}
	else
		cout << "no project can be added further already have 50 projects" << endl;
}

void Company::AssignProjectToEmployee(int projID , int empID) {
	Project* pr = NULL;
	Employee* emp = NULL;
	for (int i = 0; i < 50; i++) {
		if (this->project[i] && this->project[i]->getID() == projID) {
			pr = this->project[i];
			break;
		}
	}
	for (int i = 0; i < 500; i++) {
		if (this->employee[i] && this->employee[i]->getID() == empID) {
			emp = this->employee[i];
			break;
		}
	}
	if (pr != NULL && emp != NULL) {
		pr->AssignToEmployee(emp);
		emp->AddProject(pr);
	}
	else {
		cout << "Not successful assignment of project " << endl;
	}
}
void Company::AssignEmployeeToDepartment(int deptID, int empID) {
	Department* dept = NULL;
	Employee* emp = NULL;
	for (int i = 0; i < 20; i++) {
		if (this->project[i] && this->department[i]->getID() == deptID) {
			dept = this->department[i];
			break;
		}
	}
	for (int i = 0; i < 500; i++) {
		if (this->employee[i] && this->employee[i]->getID() == empID) {
			emp = this->employee[i];
			break;
		}
	}
	if (dept != NULL && emp != NULL) {
		dept ->AddEmployee(emp);
		emp->SetDepartment(dept);
	}
	else {
		cout << "Not successful assignment of department " << endl;
	}
}

void Company::displayProjects() {
	for (int i = 0; i < projectCount; i++) {
		this->project[i]->displayProjectInfo();
	}
}

void Company::displayEmployees() {
	for (int i = 0; i < employeeCount; i++) {
		this->employee[i]->displayEmployeeInfo();
	}
}
void Company::displayDepartments() {
	for (int i = 0; i < deptCount; i++) {
		this->department[i]->displayDeptInfo();
	}
}

//void Company::removeEmployeeFromDepartment(int projID, int empID) {
//
//}