#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "move.h"
#include "drawmap.h"
#include <windows.h>
#include <conio.h>
#include <graphics.h>
Move move;
int maxscore;
int main()
{
    FILE* tfp;
    tfp = fopen("./maxscore.txt", "a+");
    fclose(tfp);
    tfp = NULL;
    readfile();
    IMAGE img;
    initgraph(450, 647);
    loadimage(&img, _T("image//background.png"));
    putimage(0, 0, &img);
    drawmap(move.map, move.curscore);
    while (1)
    {
        char ch = _getch();
        switch (ch)
        {
        case 'w':
            move.up();
            break;
        case 's':
            move.down();
            break;
        case 'a':
            move.left();
            break;
        case 'd':
            move.right();
            break;
        case 'q':
            exit(0);
        }
        drawmap(move.map,move.curscore);
        if (move.flag == 2)
        {
            /*Jundge(move.curscore);*/
            Sleep(10000);
            exit(0);
        }
        if (move.flag == 1)
        {
            /*Jundge(move.curscore); */
            Sleep(1000);
            exit(0);
        }
    }
    closegraph();
    return 0;
}