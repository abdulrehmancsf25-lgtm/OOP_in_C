#include <iostream>
using namespace std;
class Person{
    public:
   
    static int cnt ;
    string name ;
    int age ;
    Person(){
            name = "unkown" ;
            age = 100 ;
    }
    // static int getCount()const{
                            // static func can not be const
                            // const is related to object change
    // }

} ;
int Person :: cnt = 0 ;
int main() {
            Person p ;
            Person x(p) ;
            
            //Person& x(p) ;
            // x.name = "abdul" ;
            // cout << p.name << " " << x.name << endl; 
    return 0;
}