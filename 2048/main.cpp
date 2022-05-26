#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "move.h"
#include "drawmap.h"
#include <windows.h>
#include <conio.h>
#include <graphics.h>
int moveflag ;
Move move;
int maxscore;
int main()
{
    FILE* tfp;
    tfp = fopen("./maxscore.txt", "a+");
    fclose(tfp);
    tfp = NULL;
    readfile();
    initgraph(450, 647);
    IMAGE image;
    drawmap(move.map, move.curscore);
    while (1)
    {
        char ch = _getch();
        switch (ch)
        {
        case 'w':
            moveflag = 1;
            move.up();
            break;
        case 's':
            moveflag = 2;
            move.down();
            break;
        case 'a':
            moveflag = 3;
            move.left();
            break;
        case 'd':
            moveflag = 4;
            move.right();
            break;
        case 'q':
            exit(0);
        }
        drawmap(move.map,move.curscore);
        if (move.flag == 2)
        {
            Jundge(move.curscore);
            Sleep(10000);
            /*goodbye();*/
            exit(0);
        }
        if (move.flag == 1)
        {
            Jundge(move.curscore); 
            Sleep(1000);
            /*goodbye();*/
            exit(0);
        }
    }
    closegraph();
    return 0;
}