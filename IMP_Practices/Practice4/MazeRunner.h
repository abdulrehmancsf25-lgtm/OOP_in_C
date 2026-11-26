#pragma once
#include<iostream>
using namespace std ;

class MazeRunner{
        
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

    public:
        MazeRunner(int , int ,int , int ,int);
        bool isMazeFinished();
        void printRunner();
        void updateDirection();

};