#include "MazeRunner.h"
#include "ConsoleFunctions.h"

ConsoleFunctions cfunc2;

MazeRunner::MazeRunner(int x, int y, int color, int maze_rows, int maze_cols, Grid &obj)
{   // Ctor
    // USUALLY x,y = (0,0)
    this->x = prev_x = x;
    this->y = prev_y = y;
    this->color = color;
    this->maze_rows = maze_rows;
    this->maze_cols = maze_cols;
    this->dir = RIGHT;
    this->arr = obj.arr; // now arr is our 2D Grid
}

bool MazeRunner::isMazeFinished()
{ // Checks if runner has reached the end of maze (find the end door)
    for (int i = 0; i < this->maze_rows; i++)
    {
        if (this->arr[i][maze_cols - 1] == '0' && x == i && y == maze_cols - 1)
            return true;
    }
    return false;
}
void MazeRunner::printRunner()
{ // INCOMPLETE

    cfunc2.SetCursorAt(this->prev_y, this->prev_x);
    cfunc2.SetColor(black, black);
    cout << " ";
    cfunc2.SetCursorAt(this->y, this->x);
    cfunc2.SetColor(this->color, black);
    cout << char(2);
}

void MazeRunner::updateDirection()
{
    prev_x = x;
    prev_y = y;

    if (dir == RIGHT)
    {
        if (!out_of_bound(x + 1, y) && arr[x + 1][y] == '0')
            dir = DOWN;

        else if (!out_of_bound(x, y + 1) && arr[x][y + 1] == '0')
            dir = RIGHT;

        else if (!out_of_bound(x - 1, y) && arr[x - 1][y] == '0')
            dir = UP;
        else if (!out_of_bound(x, y - 1) && arr[x][y - 1] == '0')
            dir = LEFT;
    }

    else if (dir == UP)
    {

        if (!out_of_bound(x, y + 1) && arr[x][y + 1] == '0')
            dir = RIGHT;

        else if (!out_of_bound(x - 1, y) && arr[x - 1][y] == '0')
            dir = UP;

        else if (!out_of_bound(x, y - 1) && arr[x][y - 1] == '0')
            dir = LEFT;

        else if (!out_of_bound(x + 1, y) && arr[x + 1][y] == '0')
            dir = DOWN;
    }

    else if (dir == LEFT)
    {

        if (!out_of_bound(x - 1, y) && arr[x - 1][y] == '0')
            dir = UP;

        else if (!out_of_bound(x, y - 1) && arr[x][y - 1] == '0')
            dir = LEFT;

        else if (!out_of_bound(x + 1, y) && arr[x + 1][y] == '0')
            dir = DOWN;

        else if (!out_of_bound(x, y + 1) && arr[x][y + 1] == '0')
            dir = RIGHT;
    }

    else if (dir == DOWN)
    {

        if (!out_of_bound(x, y - 1) && arr[x][y - 1] == '0')
            dir = LEFT;

        else if (!out_of_bound(x + 1, y) && arr[x + 1][y] == '0')
            dir = DOWN;

        else if (!out_of_bound(x, y + 1) && arr[x][y + 1] == '0')
            dir = RIGHT;

        else if (!out_of_bound(x - 1, y) && arr[x - 1][y] == '0')
            dir = UP;
    }
}
void MazeRunner::move()
{
    if (dir == UP)
        x = x - 1;
    else if (dir == RIGHT)
        y = y + 1;
    else if (dir == DOWN)
        x = x + 1;
    else
        y = y - 1;
}
bool MazeRunner::out_of_bound(int x, int y)
{
    if (x < 0 || x == maze_rows || y < 0 || y == maze_cols)
        return true;
    return false;
}
void MazeRunner::delay(int x)
{
    cfunc2.timesleep(x);
}
