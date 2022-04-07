#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "move.h"
#include "drawmap.h"
#include <windows.h>
#include <conio.h>
#include <graphics.h>
int main()
{
    Move move;
    IMAGE img;
    initgraph(450,647);
    loadimage(&img, _T("./image/background.png"));
    putimage(0,0,&img);
    drawmap(move.map);
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
        system("cls");
        drawmap(move.map);
        if (move.flag == 2)
        {
            system("cls");
            printf("*******************\n");
            printf("   You win! ¹§Ï²£¡  \n");
            printf("*******************\n");
            Sleep(10000);
            exit(0);
        }
        if (move.flag == 1)
        {
            system("cls");
            printf("*******************\n");
            printf("   You Lose! ±ð»ÒÐÄ£¡  \n");
            printf("*******************\n");
            Sleep(1000);
            closegraph();
            exit(0);
        }
    }
    closegraph();
    return 0;
}