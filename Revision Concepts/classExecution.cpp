#include <iostream>
using namespace std;
class pr{
        public:
        const char * name ;
         int age ;
        pr():name(NULL){
            cout << "Default Ctor"<< endl ;
            
            age = 100 ;
        }
        pr(const char* name):name(name){
            cout << "Single arg Ctor" << endl ;
            age = 0 ;
        }
        pr(const pr& temp){
            cout << "copy Ctor " << endl ;
            this->name = temp.name ;
            this -> age = temp.age ;
        }
};
void byValue(pr temp){
    cout << temp.name << endl;
}

int main() {
    //        pr P1; // def
    //    // pr P2 = pr("hello") ;
    //     byValue(pr("hi")) ;
            pr  P1 = "hello" ;
            byValue(P1) ;


    return 0;
}
















// #include <iostream>
// using namespace std;
// class Example {
//     public:
//     int y; // Declared first
//     int x; // Declared second
// public:
//     // PITFALL: Even though x is first in the list, y is initialized first.
//     // If y depends on x here, it will result in undefined behavior (garbage value).
//     Example(int val) : x(val), y(x) { 
//         // Constructor body runs last
//     } 
// };
// int main() {
//             Example e1(5) ;
//             cout << e1.y << endl ; // garbage 
//     return 0;
// }