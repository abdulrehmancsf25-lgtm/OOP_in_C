#include <iostream>
using namespace std;
void update(int* ptr){
    // pointer copy is made but address inside ptr is same 
        *ptr = 100 ;
        ptr++ ;
}
void func(int*arr){
    cout <<" inside : "<<  arr[0] << endl ;
}
int main() {

        //     int arr[5] = {1,2,3,4,5} ;
        //     func(arr+1) ;
        //     cout << " in main : " << arr[0] << endl ;

        // int first = 10 ;
        // int second = 20 ;
        // int *p = &first ;
        // int ** q = &p ;
        // *q = &second ;
        // (*p)++ ;
        // cout << first << "  " << second<< endl ;


        int first = 110 ;      // IMP CONCEPT 
        int * p = &first ;
        int** q = &p ;
        int sec = (**q)++ + 9 ;
        cout << first << "  " << sec << endl ;



            int x = 10 ;
            int* ptr = &x ;
            cout << " Before : " << ptr << " value : " << *ptr << endl ;
            update(ptr) ;
           cout <<" after : " <<  ptr << " value : " << *ptr <<  endl ;

        char ch = 'a' ;
        ch++ ;
        cout << ch ;

    return 0;
}