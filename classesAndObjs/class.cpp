#include <iostream>
using namespace std;
class Person
{
public:
    string name;
    int age;
    char gender;
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
    Person *p1 = new Person("abdul", 19, 'M');
    p1->display();
    delete p1;
    return 0;
}