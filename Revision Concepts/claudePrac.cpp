#include <iostream>
#include <string>
using namespace std;

class pr {
public:
    string name;
    int age;
    string madeBy;   // records which constructor built this object

    pr() : name("unknown"), age(100), madeBy("Default Ctor") {
        cout << "  [Default Ctor]\n";
    }

    pr(const string& name) : name(name), age(0), madeBy("Single-arg Ctor") {
        cout << "  [Single-arg Ctor]\n";
    }

    pr(const string& name, int age) : name(name), age(age), madeBy("Two-arg Ctor") {
        cout << "  [Two-arg Ctor]\n";
    }

    pr(const pr& other) : name(other.name), age(other.age), madeBy("Copy Ctor") {
        cout << "  [Copy Ctor]\n";
    }

    pr& operator=(const pr& other) {
        cout << "  [Copy Assignment]\n";
        if (this != &other) {          // self-assignment check belongs HERE
            name = other.name;
            age = other.age;
            madeBy = "Copy Assignment (after " + madeBy + ")";
        }
        return *this;
    }

    ~pr() {
        cout << "  [Dtor] " << name << " (" << madeBy << ")\n";
    }

    void show(const string& label) const {
        cout << label << " -> name=" << name << ", age=" << age
             << ", madeBy=" << madeBy << "\n";
    }
};

void byValue(pr temp) { cout << "  inside byValue\n"; }
void byRef(const pr& temp) { cout << "  inside byRef\n"; }
pr   makePr() { return pr("fromFunction"); }

int main() {
    // cout << "1. pr a;\n";               pr a;                   a.show("a");
    cout << "2. pr b(\"hello\");\n";    pr b("hello");       
    // cout << "3. pr c = string(\"hi\");\n"; pr c = string("hi");  c.show("c");
//    cout << "5. pr e(b);\n";            pr e(b);                e.show("e");
//     cout << "6. pr f = b;\n";           pr f = b;               f.show("f");   

 cout << "8. byValue(b);\n";         byValue(b);
    return 0;
}