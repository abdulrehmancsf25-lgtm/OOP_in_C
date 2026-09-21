#include <iostream>
#include<fstream>
using namespace std;

int main() {
            // fstream readWrite("file1.txt") ;
            //  if(!readWrite.is_open())
            //    return 1 ;
            // readWrite << 1 << 2 << 3 << 4 ;
            // readWrite.close() ;
           
            // fstream in("file1.txt");
            //  int n ;
            //  in >> n ;
            //  cout << n ;
            //  in.close() ;
           
            // write in file 
            // ofstream wr("file1.txt");
            // if(!wr.is_open())
            //   return 1 ;
            // while(1){
            //     int n ;
            //     cin >> n ;
            //     if(n == -1)
            //      break ;
            //     wr << n << " " ;
            // }
            // wr.close();
             
            // appending in file
            // ofstream wr2("file1.txt" ,ios::app);
            // if(!wr2.is_open())
            //  return 1 ;
            // wr2 << endl  << 0 << " " << 3 ;
            // wr2.close() ;

          // reading 
          int arr[100] ;
          int cnt = 0 ;
          for(int i = 0 ; i < 100 ; i++)
            arr[i] = INT_MIN ;
          ifstream read("file1.txt");
          int n ; 
           while(read >> n){
             arr[cnt++] = n ;
           }
           read.close() ;

           // printing array 
           cout << "total count " << cnt << endl ;
           for(int i = 0 ; i < 100 ; i++){
             if(arr[i] == INT_MIN)
               break ;
              cout << arr[i] << " " ;
           }
     return 0;
}
