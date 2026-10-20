#include "MazeRunner.h"
#include "ConsoleFunctions.h"
#include "Maze.h"
using namespace std;

bool win_helper(int key, int *arr, int Size)
{ // for more racers in game
	for (int i = 0; i < Size; i++)
		if (arr[i] == key)
			return true;
	return false;
}

int main()
{

	Maze m1;
	m1.printMaze();

	// MAKING A GRID OBJ TO BE USED IN MAZERUNNER CLASS
	Grid screen(m1.rows, m1.cols);

	// TASK 3 (3 RUNNERS)
	MazeRunner arr[3] = {MazeRunner(1, 1, green, m1.rows, m1.cols, screen),
						 MazeRunner(1, 2, blue, m1.rows, m1.cols, screen),
						 MazeRunner(1, 3, gray, m1.rows, m1.cols, screen)};
	int finish[3] = {-1, -1, -1};
	int cnt = 0;

	while (1)
	{
		if (arr[0].isMazeFinished() && !win_helper(1, finish, 3))
			finish[cnt++] = 1;

		if (arr[1].isMazeFinished() && !win_helper(2, finish, 3))
			finish[cnt++] = 2;

		if (arr[2].isMazeFinished() && !win_helper(3, finish, 3))
			finish[cnt++] = 3;

		if (arr[0].isMazeFinished() && arr[1].isMazeFinished() && arr[2].isMazeFinished())
			break;

		if (!arr[2].isMazeFinished())
		{
			arr[2].printRunner();
			arr[2].updateDirection();
			arr[2].move();
		}
		if (!arr[1].isMazeFinished())
		{
			arr[1].printRunner();
			arr[1].updateDirection();
			arr[1].move();
		}
		if (!arr[0].isMazeFinished())
		{
			arr[0].printRunner();
			arr[0].updateDirection();
			arr[0].move();
		}

		MazeRunner::delay(100);
	}

	ConsoleFunctions cf1;
	cf1.SetCursorAt(0, 14);

	// plaerys for task3
	cf1.SetColor(green, black);
	cout << "Player 1 : " << char(2) << endl;

	cf1.SetColor(blue, black);
	cout << "Player 2 : " << char(2) << endl;

	cf1.SetColor(gray, black);
	cout << "Player 3 : " << char(2) << endl;

	cf1.SetColor(white, black);

	cout << "First position : " << "Racer " << finish[0] << endl;
	cout << "Second position : " << "Racer " << finish[1] << endl;
	cout << "Third position : " << "Racer " << finish[2] << endl;

	return 0;
}