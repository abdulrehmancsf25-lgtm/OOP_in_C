#include <iostream>
using namespace std;

int main()
{
    // char arr[10] ;
    // cin >> arr ; // from hello world stores hello "world\n" remains in buffer
    // char arr2[10] ; // ignores space store till o
    // cin >> arr2 ; // takes input from stream -> world
    // cout << "char array 1 " << arr << endl ;
    // cout << "char array 2 " << arr2 << endl;

    //   string arr2 ;
    //   cin >> arr2 ; // takes input untill hits space or \n
    //   cout << arr2 << endl ;
    //   // use cin.ignore to avoid stream use again
    //   cin.ignore(100,'\n') ; // takes up to 100 chars or stops at \n
    //   cin >> arr2 ;
    //   cout << "again : " << arr2 ;

       char arr3[18] = "hello how are you" ;
      cout << arr3 << " " << arr3+1 << " " << arr3+2 << endl ;
       // same as
     cout << &arr3[0] << " " << &arr3[1] << " " << &arr3[2] << endl ;
       // VS
       cout << arr3[0] << " " << arr3[1] << " " << arr3[2] << endl;

      // to print address
      cout << "Addresess : " << endl;
      cout << (void*)arr3 << "  " << (void*)&arr3[0] << endl ;

     // other ways to creata char array
     char ar1[] = "hello";
     // char ar1[] ; // not valid
     char ar2[] = {'h', 'e', 'l', 'l', 'o', '\0'};
     cout << ar1 << endl;
     cout << ar2 << endl;
    


    // NOW TO AVOID BUFFER PROBLEM AN TO STORE WHOLE STRING
    // USE get or getline(preferable) 

    // get lefts \n in stream VS getline handles it carefully
    char arr[10] ;
    cin.get(arr ,10,'\n') ; //1234567890 results in 123456789 one space for \0
    cout << arr << endl ;
    
    cin.ignore(100 ,'\n') ; // for removing 0 and \n from stream

    cin.getline(arr , 10 , '\n') ;
    cout << arr ; // no need for .ignore


    return 0;
}