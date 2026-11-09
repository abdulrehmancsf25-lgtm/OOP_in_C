#include <iostream>
using namespace std;

int main() {
            int n ;
            cout << "enter rows " ;
            cin >> n ;
            int ** arr = new int*[n] ;
            int *temp = new int[n] ;
            // memory allocation 
            for(int i = 0 ; i < n ; i++){
                    int x ;
                    cout << "enter no. of cols for row " << i << " : " ;
                    cin >> x ;
                    temp[i] = x ;
                    arr[i] = new int[x] ;
            }
            
           
        // input 
        for (int i = 0; i < n; i++) {
            cout << "enter input for r " << i << " : " ;
            for(int j = 0 ; j < temp[i] ; j++){
                    cin >> arr[i][j] ;
            }
            
        }

            for (int i = 0; i < n; i++) {
                for(int j = 0 ; j < temp[i] ; j++){
                    cout <<  arr[i][j]  << "  ";
                }
                cout<< endl ;
            }
    return 0;
}