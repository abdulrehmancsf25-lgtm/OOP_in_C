#include"Department.h"
Department::Department(int ID, CharString name):name(name){

	this->ID = ID;
	this->employeeCount = 0;
	for (int i = 0; i < 50; i++)
		this->employee[i] = NULL;

}
void Department::displayDeptInfo() {
	cout << "Department ID : " << this->ID << endl;
	cout << "Name : ";
	this->name.print();
	cout << "Department has : " << this->employeeCount <<" employees." << endl;
}

bool Department::AddEmployee(Employee* emp) {
	if (!(emp->SetDepartment(this)))
		return false;

	if (this->employeeCount < 50) {
		this->employee[employeeCount++] = emp;
		return true;
	}
	cout << "Employee can't be assigned to Department : " << this->ID << endl;
	cout << "Department has already 50 employees " << endl;
	return false;
}
bool Department::RemoveEmployee(int EmpID) {
	if (this->employeeCount <= 0) {
		cout << "Department " << this->ID << "ihas not any employee " << endl;
		return false;
	}

	for (int i = 0; i < this->employeeCount; i++) { // check for present
		if (employee[i]->getID() == EmpID) {
			// employee found 
			employee[i]->SetAssignedToDept(false);
			employee[i] = NULL;
			for (int i = 1; i < 50;i++) {
				if (employee[i - 1] == NULL) {
					employee[i - 1] = employee[i];
					employee[i] = NULL;
				}
			}
			this->employeeCount -= 1;
			return true;
		}
	}
	cout << "Department has not an Employee with ID : " << EmpID << endl;
	return false;
}

void Department::DisplayAllEmployee() {
	for (int i = 0; i < this->employeeCount;i++) {
		this->employee[i]->displayEmployeeInfo();
	}
}

int Department::getID()const {
	return this->ID;
}