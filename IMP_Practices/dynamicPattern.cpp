#include <iostream>
#include <climits>
#include <fstream>
using namespace std;
int main()
{
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

    // now read file
    // vector to store the digits
    int columns[100];
    int cnt = 0;
    // intitializing with INT_MIN to track no of digits

    for (int i = 0; i < 100; i++)
        columns[i] = INT_MIN;

    ifstream read("file1.txt");
    if (!read.is_open())
    {
        cout << "File not accessible" << endl;
        return 1;
    }

    int n;
    while (read >> n)
        columns[cnt++] = n;

    read.close();

    // now create 2d dynamic array
    char **arr = new char *[cnt];
    for (int i = 0; i < cnt; i++)
    {
        if (columns[i] == 0)
            arr[i] = NULL;

        else
        {
            arr[i] = new char[columns[i]];
            for (int j = 0; j < columns[i]; j++)
            {
                arr[i][j] = '*';
            }
        }
    }
    // finding max of columns vector
    int maxi = INT_MIN;
    for (auto i : columns)
        if (i > maxi)
            maxi = i;
    maxi -= 1;
    // printing array
    // outer loop == total rows
    // inner loop == max value in columns = maxi
    // column wise traverse
    // columns wise
    for (int j = maxi; j >= 0; j--)
    {
        for (int i = 0; i < cnt; i++)
        {
            if (j == 0 && arr[i] == NULL)
                cout << '-';
            else if (j >= columns[i])
                cout << ' ';
            else
                cout << arr[i][j];
        }
        cout << endl;
    }

    // memory free
    for (int i = 0; i < cnt; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}