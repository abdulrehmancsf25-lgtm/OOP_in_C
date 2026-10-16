#include <iostream>
using namespace std;
class Person{
            public:
            string name ;
            int age ;
            inline static int cnt = 0;
            const int id ;
      
        Person(string name , int age ):name(name) ,age(age),id(++cnt){}
        
        int getID(){
            return cnt ;
        }
};
int main() {
             Person p1 ;
    return 0;
}