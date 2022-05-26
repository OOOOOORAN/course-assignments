#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <graphics.h>
#include <string>
#include <cstring>
extern int maxscore;
void drawmap(int map[6][6],int curscore)
{
    cleardevice();
    char print[50];
    IMAGE image;
    IMAGE hover;
    loadimage(&image, _T("image//background.png"));
    putimage(0, 0, &image);
    setbkmode(TRANSPARENT);
    loadimage(&image, _T("image//main.png"));
    putimage(0, 200, &image);
    settextcolor(WHITE);
    settextstyle(80, 0,"Brush Script MT");
    outtextxy(175, 0, "2048");
    settextcolor(WHITE);
    settextstyle(35, 0, _T("华文行楷"),0,0,50,false,false,false);
    std::string max = "历史最高分数为：" + std::to_string(maxscore);
    strcpy(print, max.c_str());
    outtextxy(15, 75, print);
    settextstyle(35, 0,_T("华文行楷"), 0, 0, 50, false, false, false);
    std::string cur = "当前分数为：" + std::to_string(curscore);
    strcpy(print, cur.c_str());
    outtextxy(15, 125, print);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (map[i][j] == 2)
            {
                loadimage(&hover, _T("image//2.png"));
                putimage(10*j+100* (j-1), 200+i*10+100 * (i-1), &hover);
            }
            if (map[i][j] == 4)
            {
                loadimage(&hover, _T("image//4.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 8)
            {
                loadimage(&hover, _T("image//8.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 16)
            {
                loadimage(&hover, _T("image//16.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 32)
            {
                loadimage(&hover, _T("image//32.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 64)
            {
                loadimage(&hover, _T("image//64.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 128)
            {
                loadimage(&hover, _T("image//128.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 256)
            {
                loadimage(&hover, _T("image//256.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 512)
            {
                loadimage(&hover, _T("image//512.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 1024)
            {
                loadimage(&hover, _T("image//1024.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 2048)
            {
                loadimage(&image, _T("image//2048.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
        }
    }
}
void readfile()
{
    FILE* tfp;
    tfp = fopen("maxscore.txt", "r+");
    fseek(tfp, 0, SEEK_SET);//fseek可以将文件指针移动到文件的特定位置
    fscanf_s(tfp,"%d",&maxscore);
    fclose(tfp);
    tfp = NULL;
}
void writefile(int curscore)
{
    FILE* tfp = fopen("maxscore.txt", "w+");
    fseek(tfp, 0, SEEK_SET);
    fprintf(tfp, "%d", curscore);
    fclose(tfp);
    tfp = NULL;
}
void Jundge(int curscore)
{
    if (curscore>maxscore) writefile(curscore);
}
void goodbye()
{
    IMAGE image;
    loadimage(&image, _T("image//background.png"));
    putimage(0, 0,&image);
}