#include <iostream>
using namespace std;
class Person
{
public:
    string name;
    int age;
    char gender;
    // Constructor
    Person(string name, int age, int gender) : name(name), age(age), gender(gender)
    {
    }
    // class method / member function
    void display() const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};
class Student : public Person // single inheritance
{
public:
    string grade;
    string university;
    // constructor
    Student(string name, int age, char gender, string grade, string uni) : Person(name, age, gender), grade(grade), university(uni) {}

    void display()
    {
        Person::display(); // use of inherited  func display
                           /*If the display() function in the Person class was not declared as virtual,
                            then this is not an override.
                            Instead, it is called function hiding (or shadowing).
                   
                   
                           The Difference: Without virtual, C++ does not support runtime polymorphism.
                           If you have a pointer of type Person* pointing to an object of your derived class and you call ptr->display(),
                           it will execute Person::display() instead of your derived class's version.*/
        cout << "Class : " << grade << endl;
        cout << "University : " << university << endl;
    }
};
int main()
{
    cout << "Person obj details" << endl;
    Person *p1 = new Person("abdul", 19, 'M');
    p1->display();

    cout << "Student obj details " << endl;
    Student s1("ali", 20, 'M', "14th_grade", "PUCIT");
    s1.display();
    delete p1;
    return 0;
}