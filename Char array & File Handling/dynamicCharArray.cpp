#include <iostream>
using namespace std;

int main() {
            // char* arr = new char[10] ;
            // cin >> *arr ; // input hello arr[0] = only first char 
            // cin >> *(arr+1) ; //arr[1] = e
            // cin >> *(arr+2) ;// arr[2] = l
            // arr[3] = '\0' ; // null in arr[4]
            // cout << arr << endl ;

            // char s[5] ;
            // cin >> s ; // takes lo\n from buffer 
            // cout << s << endl ;
            // cin >> s ;
            // cout << s ;

            // delete[] arr ;

            char* ar1 = new char[]{"top"} ;
             cout << ar1 << endl ;
             *ar1 = 'c' ; // changes arr[0] 
             cout << ar1 << endl;
    return 0;
}