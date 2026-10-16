#include <iostream>
using namespace std;
class Person
{
public:
    string name;
    int age;
    char gender;
    Person(){
        name = "none" ;
        age = 0 ;
        gender = 'O' ;
    };
    Person(string name, int age, int gender) : name(name), age(age), gender(gender)
    {
    }
    void display() const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};
int main()
{
    // Person *p1 = new Person("abdul", 19, 'M');
    // p1->display();
    // delete p1;


    Person* arr = new Person[5];

    for(int i = 0 ; i < 5 ; i++)
       arr[i].display() ;

    return 0;
}