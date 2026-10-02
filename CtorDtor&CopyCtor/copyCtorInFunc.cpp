// #include <iostream>
// using namespace std;
// class person
// {
// private:
//     /* data */

//     string name;
//     inline static int cnt = 0;
//     int age;
//     int id;
//     char gender;

// public:
//     person()
//     {
//         cout << "Ctor called";
//         name = ' ';
//         age = 0;
//         gender = ' ';
//     }
//     person(string name, int age, char gender) : name(name), age(age), gender(gender) , id(++cnt){

//                     cout << "Ctor called for id " << id << endl ;}
//             ~person(){
//                 cout << "Dtor called for id " << id << endl ;
//             }
//     person(const person& other){
//         cout << "Copy Ctor is called for id : " << other.id << endl;
//                     this->name = other.name ;
//                     this->age =other.age ;
//                     this->gender = other.gender ;
//                     this -> id = other.id ;

//     }

// };
// person modify(person m){
//                  cout << "inside function  copy ctor is called " << endl;
//                  return m;
// }
// int main()
// {
//     // person p1("abdul" ,19 ,'M') ;
//     // person p2 = modify(p1) ;
//       string s1 = "abdul" ;
//       string s2 = "_rehman" ;
//       cout << s1+s2 << endl ;

//     return 0;
// }
#include <iostream>
#include <string>
using namespace std;

class Tracer
{
    string name;

public:
    Tracer(string n) : name(n)
    {
        cout << "  CTOR      " << name << endl;
    }
    Tracer(const Tracer &o) : name(o.name + "_copy")
    {
        cout << "  COPY CTOR " << name << " (from " << o.name << ")" << endl;
    }
    ~Tracer()
    {
        cout << "  DTOR      " << name << endl;
    }
};

void byValue(Tracer t) { cout << "  inside byValue" << endl; }
void byRef(const Tracer &t) { cout << "  inside byRef" << endl; }

int main()
{
    cout << "1. Create a, b\n";
    Tracer a("a");
    Tracer b("b");

    cout << "2. Inner scope\n";
    {
        Tracer c("c");
        cout << "  leaving scope\n";
    }

    cout << "3. Pass by value\n";
    byValue(a);

    cout << "4. Pass by reference\n";
    byRef(b);

    cout << "5. Copy initialization\n";
    Tracer d = a;

    cout << "6. Heap object\n";
    Tracer *e = new Tracer("e");
    delete e;

    // cout << "7. Temporary\n";
    // Tracer("temp");
    // cout << "  after temp line\n";

    // cout << "8. End of main\n";
    return 0;
}