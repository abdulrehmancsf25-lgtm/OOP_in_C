#include <iostream>
#include "Employee.h"
#include "Computer.h"
using namespace std;
 
int main()
{   
    // ASSOCIATION 
    
    // An empoyee uses a computer (week relation)
    // A computer exists even if an employee leaves
    // An emloyee still lives even if no computer is assigned to him

    Employee emp1; 
    emp1.name = "Abdul";
    
    Computer *c1 = new Computer();
    c1->model = "Core I7";
    emp1.computer = c1;
    c1->employee = &emp1;

    cout << emp1.name << endl;
    cout << emp1.computer->model << endl;
     
    delete c1;


    

    return 0;
}