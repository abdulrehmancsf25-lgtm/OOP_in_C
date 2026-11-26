#pragma once
#include<iostream>
class Maze {
public:
	int rows;
	int cols;
	Maze();
	int getRows()const;
	int getCols()const;
	void printMaze();

};