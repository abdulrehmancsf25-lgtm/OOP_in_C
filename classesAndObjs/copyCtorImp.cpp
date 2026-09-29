#include <iostream>
#include<cstring>
using namespace std;
class Person{
            private:
            char* name ;
            char* gender ;
            int age ;
            void cpy(char* dest , char* src){
                int i = 0  ;
                for(; src[i] != '\0' ; i++){
                    dest[i] = src[i] ;
                }
                dest[i] = '\0' ;
            }
            public:
            Person(char* name=NULL , char* gender=NULL , int age=0 ):name(name) , gender(gender){ // also behave as default constructor \addtogroup
                if(name){
                this->name = new char[strlen(name)+1] ;
                cpy(this->name ,name ) ;}
                if(gender){
                this->gender = new char[strlen(gender) +1] ;
                cpy(this->gender ,gender) ;
                }
                this->age = age ;
            }    

            void print_details(){
                if(this->name)
                cout << "Name : " << this->name << endl ;
                if(this->gender)
                cout << "Gender : " << gender << endl ;
                cout << "Age : " << age << endl ;
            }
};
int main() {
            Person h ;
            h.print_details() ;
            
    return 0;
}




















// #include <iostream>
// using namespace std;
// class Person {
// public:
//    char* name ;
//    int age ;
// };


// int main() {
//              Person h;
//              Person q = Person() ; 

//              Person* s = new Person; // OR
//              Person* t = new Person() ; // SAME 

//              h.name = "hamza" ;
//              q.name = "qimam" ;
//              (*s).name = "sammy" ;
//              t -> name = "tonny";

//             cout << h.name << " " << q.name << " " << s-> name << " " << t-> name << endl ;
//             return 0 ;
// }