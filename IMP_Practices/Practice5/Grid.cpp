#include <fstream>
#include<iostream>
using namespace std;

class Grid {
public:
	
	char** arr = NULL;
	int rows, cols;

	Grid(int rows, int cols) {
		this->rows = rows;
		this->cols = cols;
		this->arr = new char*[rows];
		for (int i = 0; i < rows; i++)
			arr[i] = new char[cols];

		ifstream read("maze.txt");
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				char ch;
				read >> ch;
				this->arr[i][j] = ch;
			}
		}
	}
	~Grid(){
		for (int i = 0; i < this->rows; i++)
			delete[]this ->arr[i];
		delete[]this->arr;
	}

	
};
