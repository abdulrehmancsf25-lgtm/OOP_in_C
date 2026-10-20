#pragma once
#include "Grid.cpp"
using namespace std ;

class MazeRunner{
        
        char** arr; // for traversing array as Maze

        inline static int UP = 1;
        inline static int RIGHT = 2 ;
        inline static int DOWN =3 ;
        inline static int LEFT =  4;
       
        int prev_x;
        int prev_y;
        int x ;
        int y ;
        int color ;
        int dir;
        int maze_rows ;
        int maze_cols ;
        bool out_of_bound(int ,int);

    public:
        MazeRunner(int , int ,int , int ,int ,Grid &obj);
        bool isMazeFinished();
        void printRunner();
        void updateDirection();
        void move();
        static void delay(int);

};