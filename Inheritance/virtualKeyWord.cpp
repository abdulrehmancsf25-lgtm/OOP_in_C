#include <iostream>
using namespace std;
// we need virtual key word for abstraction
// if we store shape* s = new circle() ;
// and call any function without virtual it goes for shape class not for circle class
class Shape
{
public:
    virtual void print() const
    {
        cout << "It is a shape " << endl;
    };
};

class circle : public Shape
{
    // my choice to overrride or not
};

class rectangle : public Shape
{
    // overrriding
public:
    void print() const override
    {
        cout << "This is a rectangle " << endl;
    }
};
int main()
{
    Shape s1; // obj of simple vitual function class possible
    circle c1;
    c1.print();

    rectangle r1;
    r1.print();
    return 0;
}