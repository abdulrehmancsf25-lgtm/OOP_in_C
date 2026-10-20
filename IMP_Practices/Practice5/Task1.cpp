#include "MazeRunner.h"
#include "ConsoleFunctions.h"
#include "Maze.h"
using namespace std;

int main()
{

	Maze m1;
	m1.printMaze();
	cout << "Total rows : " << m1.rows << endl;
	cout << "Total columns : " << m1.cols << endl;
	return 0;
}