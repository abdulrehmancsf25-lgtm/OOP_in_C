#include"Employee.h"
#include<iostream>
using namespace std;

Employee::Employee(int ID, CharString name, Address permanantAddress):name(name), permanantAddress(permanantAddress){
	this->projectCount = 0;
	this->assignedToDept = false;
	this->salary = 0; 
	this->dept = NULL;
	this->ID = ID;
	for (int i = 0; i < 3; i++) {
		this->project[i] = NULL;
	}
}
int Employee::getID() { 
	return this->ID;
}
void Employee::displayEmployeeInfo() {
	cout << "Employee ID : " << this->ID << endl;
	cout << "Name : ";
	this->name.print();
	cout << endl;
	cout << "Permanant Address : ";
	this->permanantAddress.displayAddress();
	cout << "Currently working in " << this->projectCount << " projects " << endl;
}


bool Employee::AddProject(Project* proj) {
	if (this->projectCount >=3 ){
		cout << "Project can't be assigned" << endl;
		cout << "Employee is already in 3 Projects " << endl;
		return false;
	}
	if (proj->AssignToEmployee(this)) {
		this->project[projectCount++] = proj;
		proj->IncEmployeeCount();
		return true;
	}
	return false;
}
bool Employee::RemoveProject(int projectID) {
	if (this ->projectCount <= 0) {
		cout << "Employee "<< this ->ID   << "is not working in any project " << endl;
		return false;
		 }
	for (int i = 0; i < this->projectCount; i++) { // check for present
		if (project[i]->getID() == projectID) {
			// project found 
			project[i]->DecEmployeeCount();
			project[i] = NULL;
			for (int i = 1; i < 3;i++) {
				if (project[i - 1] == NULL) {
					project[i - 1] = project[i];
					project[i] = NULL;
				}
			}
			this->projectCount -= 1;
			return true;
		  }
	}

	cout << "Employee is not working in the prject ID" << projectID << endl;
	return false;
}

void Employee::SetAssignedToDept(bool value) {
	this->assignedToDept = value;
}
void Employee::displayAllProjects() {
	if (this->projectCount <= 0) 
		cout << "Employee " << this->ID << "is not working in any project " << endl;
	else {
		for (int i = 0;i < this->projectCount; i++) {
			this->project[i]->displayProjectInfo();
		}
	}
 }
float Employee::getSalary()const {
	return this->salary;
}
void Employee::SetSalary(float sal) {
	this->salary = sal;
}
bool Employee::SetDepartment(Department* dept) {
	if (this->dept == NULL) {
		this->dept = dept;
		this->assignedToDept = true;
		return true;
	}
	cout << "Employee is already worrking in department " << endl;
	return false;
}