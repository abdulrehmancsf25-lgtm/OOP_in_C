#include <iostream>
#include <cstring>
using namespace std;
class Person
{
    char *name;
    char *gender;
    int age;
    inline static int cnt = 0;
    int id;

public:
    Person()
    { // Deafult Ctor
        // name = gender = age =0 ; // wrong age is int
        name = gender = 0;
        age = 0;
        id = ++cnt;
    }
    Person(const char *name, const char *gender, int age)
    { // Parametrized Ctor
        this->name = new char[strlen(name) + 1];
        this->gender = new char[strlen(gender) + 1];
        strcpy(this->name, name);
        strcpy(this->gender, gender);
        this->age = age;
        id = ++cnt;
    }

    Person(const Person &other)
    { // Copy Ctor
        this->name = new char[strlen(other.name) + 1];
        this->gender = new char[strlen(other.gender) + 1];
        strcpy(this->name, other.name);
        strcpy(this->gender, other.gender);
        this->age = other.age;
        id = ++cnt;
    }

    void print_details()
    {
        if (name && gender)
        {
            cout << "Name : " << this->name << endl;
            cout << "Gender : " << this->gender << endl;
            cout << "Age : " << this->age << endl;
        }
        else
            cout << "No data about object to display!" << endl;
    }
    ~Person()
    { // Dtor
        if (!name)
            delete[] name;
        if (!gender)
            delete[] gender;
    }
};
int main()
{
    Person p1;
    Person p2("Abdul Rehman", "Male", 19);

    p1.print_details();
    p2.print_details();

    Person p3(p2); // Ctor

    return 0;
}