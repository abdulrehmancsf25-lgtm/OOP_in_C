#include <iostream>
using namespace std;
int combination(int &n, int &r)
{
   // finding nCr
   int res = 1;
   for (int i = 0; i < r; i++)
   {
      res *= n - i;
      res /= i + 1;
   }
   return res;
}
int main()
{
   int n;
   cout << "Enter number of rows of Pascal's Triangle " << endl;
   cin >> n;

   // creating 2d array

   int **arr = new int *[n];
   // allocating columns in each row
   for (int i = 0; i < n; i++)
   {
      arr[i] = new int[i + 1];
   }

   // now array size is done
   // filling values
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j <= i; j++)
      {
         arr[i][j] = combination(i, j);
      }
   }
   // printing
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j <= i; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   return 0;
}