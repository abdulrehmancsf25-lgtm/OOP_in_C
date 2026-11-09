#include <iostream>
using namespace std;
class Person{
     public:
            string name ;
            int age ;
           
            Person():name("unkown"),age(0){}
            Person(string name , int age){
                this -> name = name ;
                this -> age = age ;
            }
            Person(const Person& p){
                        this -> name = p.name ;
                        this -> age = p.age ;
            }
};
int main(){
            int arr[5] = {1,2,3,4,5} ;
          //  cout << arr << " " << &arr << "  " << &arr[0] << endl ;


            char charr[5] = "abcd" ;
            const char* ch2 = "abcd" ;
           // cout << charr << "  " << ch2 << endl ;
            //cout << *(ch2+2) << endl ;
            cout << (charr+1) << endl ;

            cout << (void*)charr << "  " ;
            cout << (void*)(charr+1) << endl ;




}

// int main() {
//                 // // Person arr[3] ;
//                 // Person arr[3] = {Person() ,Person("abdul",19) ,Person(arr[0])} ;
//                 // cout << arr[2].name << "  " << arr[1].name << endl ;

//                 // Person *arr2[3] ;
//                 // arr2[0] = new Person() ;
//                 // arr2[1] = new Person("hamza" , 20) ;
//                 // arr2[2] = new Person(*(arr2[0])) ;
//                 // cout << arr2[0]->name << "  " << arr2[1]->name << "  " << arr2[2]->name 
//                 // << endl ;

//                 // // static arrray but dynamic objects
//                 // Person* arr[3] = { new Person() ,
//                 // new Person("hamza" , 20),
//                 // new Person(*(arr[0])) } ;
//                 //  cout << arr[0]->name << "  " << arr[1]->name << "  " << arr[2]->name 
//                 //  << endl ;

//                 // for(int i = 0 ; i < 3 ; i++){
//                 //         delete arr[i] ;
//                 //         arr[i] = NULL ;
//                 // }
           
//                 // int arr[5] = {1,2,3,4,5} ;
//                 // int* ptr = arr ;
//                 // cout << *ptr << endl ;
//                 // ptr++ ;
//                 // cout << *ptr << endl; 
//                 // ptr-- ;
//                 // cout << *ptr << endl ;
                

//                 int a = 10 , b = 9 ;
//                 int* x  = &a ;
                 
//                 // cout << *x << "  " ;
//                 // (*x)++ ;
//                 // cout << *x << endl ;

//                 // x = &b ;


//             //     const int* temp = &a ;
//             //         cout << *temp << " " ;
//             // //    (*temp)++ ; // same as static array const ptr 

//             //     temp = &b ; 
//             //     cout << *temp ;

            
//             int const* temp1 = &a ;
//             cout << *temp1 << endl ;
//             temp1 = &b ;

//             const int*  const temp2 = &a ;
//             cout << *temp2 ;
//            //  temp = &b ;


   
//     return 0;
// }