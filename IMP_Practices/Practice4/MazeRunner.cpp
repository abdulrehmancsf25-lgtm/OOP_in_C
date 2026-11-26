#include "MazeRunner.h"
#include "ConsoleFunctions.h"

ConsoleFunctions cfunc;

MazeRunner :: MazeRunner(int x , int y , int color , int maze_rows , int maze_cols){ // Ctor
        // USUALLY x,y = (0,0)
            this -> x = x ;
            this -> y = y ;
            this -> color = color ;
            this -> maze_rows = maze_rows ;
            this -> maze_cols = maze_cols ;
            this -> dir = RIGHT ;
}

bool MazeRunner :: isMazeFinished(){ // Checks if runner has reached the end of maze (find the end door)
    return (x == maze_rows - 1 && y == maze_cols -1 );
}

void MazeRunner :: printRunner(){ // INCOMPLETE 

    cfunc.SetCursorAt(this -> prev_x,this -> prev_y) ;
    cout << " " ;
    cfunc.SetCursorAt(this -> x, this -> y) ;
    cout << char(2) ;

}

void MazeRunner :: updateDirection(){

        

}