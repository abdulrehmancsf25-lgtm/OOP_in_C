#include"Employee.h"
#include"Address.h"
#include"Project.h"
#include"CharString.h"
#include"Department.h"
#include<iostream>
using namespace std;
int main() {


	CharString address1("Lahore");
	CharString name1("Abdul Rehman");
	CharString projectDesc1("A deep learning model to automate web dev");
	CharString dept1("Intelligence");


	// EMP1 
	Address add1(1, 'A', 1, address1);
	Employee e1(1, name1, add1);
	Project p1(1, projectDesc1);
	Department d1(1, dept1);
	Address add2(2, 'A', 1, address1);
	Employee e2(2, name1, add1);
	Project p2(2, projectDesc1);
	Department d2(2, dept1);

	e1.AddProject(&p1);
	d1.AddEmployee(&e1);

	e1.displayEmployeeInfo();
	cout << endl;
	p1.displayProjectInfo();
	cout << endl;
	d1.displayDeptInfo();



	// EMP1
	d1.RemoveEmployee(1);
	d1.displayDeptInfo();

	return 0;
}