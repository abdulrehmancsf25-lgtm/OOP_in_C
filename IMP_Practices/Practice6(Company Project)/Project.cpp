#include"Project.h"
#include"Employee.h"
Project::Project(int ID, CharString projectDescription):projectDescription(projectDescription){
	this->employeeCount = 0;
	this->ID = ID;
	for (int i = 0; i < 10; i++)
		this->employee[i] = NULL;

}
void Project::IncEmployeeCount() {
	this->employeeCount += 1;
}
void Project::displayProjectInfo() {
	cout << "Project ID : " << this->ID << endl;
	cout << "Project Description : ";
	this->projectDescription.print();
	cout << "Total employees in Project : " << this->employeeCount << endl;
}
int Project::getID() {
	return this->ID;
}
void Project::DecEmployeeCount() {
	if (this->employeeCount > 0)
		this->employeeCount -= 1;
}
bool Project::AssignToEmployee(Employee* emp) {
	if (this->employeeCount >= 10) {
		cout << "Already 10 employees are working on project : " << this->ID << endl;
		return false;
	}
	this->employee[this->employeeCount++] = emp;
	return true;
}
void Project::DisplayAllAssignedEmployees() {
	for (int i = 0; i < 10 && this->employee[i]; i++) {
		this->employee[i]->displayEmployeeInfo();
	}		
}