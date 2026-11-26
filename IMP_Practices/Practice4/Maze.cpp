#include "Maze.h"
#include "ConsoleFunctions.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

ConsoleFunctions cfunc;
Maze::Maze()
{
	this->cols = 0;
	this->rows = 0;
}
int Maze::getCols() const
{
	return this->cols;
}
int Maze::getRows() const
{
	return this->rows;
}
void Maze::printMaze()
{

	int cn = 0, rn = 0;

	ifstream read("maze.txt");
	if (!read)
	{
		cout << "File not opened " << endl;
		return;
	}
	string s;
	while (getline(read, s))
	{
		rn++;
		for (auto i : s)
		{
			if (rn == 1)
				cn++;
			if (i == '1')
			{
				cfunc.SetColor(white, white);
				cout << ' ';
			}
			else
			{
				cfunc.SetColor(black, black);
				cout << ' ';
			}
		}
		cfunc.SetColor(white, black); // reset before the newline
		cout << endl;
	}

	this->cols = cn;
	this->rows = rn;
}