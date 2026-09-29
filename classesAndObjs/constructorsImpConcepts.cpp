#include <iostream>
using namespace std;
class Person
{
public:
     Person() : name("abdul"), age(20) {};
     string name;
     int age;
};

int main()
{
     // Person x() ; // tring to create function named x with no arguments and return type Person
     Person x{}; // Correct (default constructor called)
     cout << x.name << " " << x.age << endl;

     Person w = Person(); // deafult constructor called
     w.name = "ali";
     w.age = 20;
     return 0;
}