#include "MazeRunner.h"
#include "ConsoleFunctions.h"
#include "Maze.h"
using namespace std;
int main() {

	Maze m1;
	m1.printMaze();


	// MAKING A GRID OBJ TO BE USED IN MAZERUNNER CLASS
	Grid screen(m1.rows, m1.cols);

	// Using rows and cols count through maze object
	   MazeRunner obj1(1, 1, 8, m1.rows, m1.cols, screen);


	   while (1) {
		   if (obj1.isMazeFinished())
			   break;
		   obj1.printRunner();
		   obj1.updateDirection();
		   obj1.move();
		   MazeRunner ::delay(150);
	   }
  

	return 0;
}