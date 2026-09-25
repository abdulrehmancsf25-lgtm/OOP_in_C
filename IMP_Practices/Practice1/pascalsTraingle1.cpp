#include <iostream>
using namespace std;
int combination(const int &n, const int &r)
{
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
	int size;
	cout << "Enter size to create n*n size matrix to store Pascal's Triangle diagonally" << endl;
	cin >> size;

	// crearing 2d array
	int **arr = new int *[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size]{0};

	// now storing in matrix
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			arr[i][j] = combination(i + j, j);
		}
	}

	// printing simply to check storage
	cout << "Stored in matrix as :" << endl;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	cout << "Actual triangle printing " << endl;
	// actaual printing
	for (int i = 0; i < size; i++)
	{
		// spaces
		for (int k = 0; k < size - i - 1; k++)
			cout << ' ';
		// values
		for (int j = 0; j <= i; j++)
			cout << arr[i - j][j] << ' ';
		cout << endl;
	}
	// free memory
	for (int i = 0; i < size; i++)
		delete[] arr[i];
	delete[] arr;
	return 0;
}