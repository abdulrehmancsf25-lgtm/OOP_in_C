#include <iostream> 
using namespace std;

int main() { 
          char temp[100] ; //  cout << sizeof(temp);
        
        cin.getline(temp , 100,'\n');
      if(temp[0] == '\0') // user enter no input 
      return 0;

        int cnt = 0 , i = 1 ;
        if(temp[0] != '\0')
          cnt++ ;
    while(i < 100 && temp[i] != '\0'){ // COUNTING CHANGING ELEMENTS TO STORE ROWS FOR 2D ARRAY
      if(temp[i] != temp[i-1])
        cnt++ ;
      i++ ;
    }

    // cout << cnt << endl ;
    // createing 2d array

    int** arr = new int*[cnt] ;
    for(int i = 0 ; i < cnt ; i++)
      arr[i] = new int[2] ; // (value : freq)

    int noCnt = 1 , n = 0 ;
     i = 0 ;
    for(; i < 99 && temp[i+1] != '\0' ; i++){
       if(temp[i] == temp[i+1])
         noCnt++ ;
        else{
             arr[n][0] = temp[i]-'0' ;
             arr[n++][1] = noCnt ;
             noCnt = 1;
        }
    }
     // check whether to add last elemnt count 
     if(n == cnt-1){
      arr[n][0] = temp[i]-'0' ;
      arr[n][1] = noCnt ;
     }
    
     // printing array
     for(int i = 0 ; i < cnt ; i++){
      cout << arr[i][0] << " : " << arr[i][1] << endl ;
     }

    // free memory
    for(int i = 0 ; i < cnt ; i++)
      delete[] arr[i] ;
    delete[] arr ;
       
          
    return 0;
}