#include <iostream>
using namespace std;
class Fraction
{
    int num;
    int den;

public:
    Fraction() : num(0), den(1) {}
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }
    friend Fraction operator+(int num, const Fraction &frac1);
    // const here will not work
    // const after function declaration means *this is not modifiable in this func
    // friend has not this pointer (not a member function )

    Fraction operator+(const Fraction &frac1) const
    {
        // Fraction temp;
        // temp.den = this->den * frac1.den;
        // temp.num = this->num * frac1.den + frac1.num * this->den;
        // return temp;
        return Fraction(this->num * frac1.den + frac1.num * this->den, this->den * frac1.den);
    }
    Fraction operator+(int num) const
    {
        return num + *this;
    }

    Fraction &operator+=(const Fraction &frac1) // why return Fraction& ->  x += y += z ;
    {
        *this = *this + frac1;
        return *this;
    }

    Fraction &operator+=(int num) // why return Fraction& ->  x += y += z ;
    {
        *this = *this + num; // overloaded already
        return *this;
    }
    void printFrac() const
    {
        cout << this->num << "/" << this->den << endl;
    }
    Fraction &operator++()
    {               // pre_Increment
        *this += 1; // overloaded already
        return *this;
    }
    Fraction operator++(int)
    { // dummy int input to overload post operators
        Fraction temp = *this;
        *this += 1;
        return temp;
    }
};
Fraction operator+(int num, const Fraction &frac1)
{ // 3+frac
    // Fraction temp;
    // temp.num = (frac1.den * num) + frac1.num;
    // temp.den = frac1.den;
    // return temp;
    return Fraction((frac1.den * num) + frac1.num, frac1.den);
}

int main()
{
    //  Fraction t1 = Fraction(2,3) ;
    //  Fraction t2(3,4) ;
    //  Fraction temp = t1+t2 ;
    //  temp.printFrac() ;
    //  t1 += t1 ;
    //  cout << "t1 += t1 : ";
    //   t1.printFrac() ;
    //  Fraction temp2 = 3+t1 ;
    // temp2.printFrac() ;

     int x = 1 , y= 2 , z= 3 ;
     cout << x << "  " << y << "  " << z << endl ;
     x += y += z ;
     cout << "AFTER : ";
    cout << x << "  " <<y << " " << z << endl ;

    Fraction fr1(2, 3);
    Fraction temp = fr1 + 1;
    temp.printFrac();
    return 0;
}