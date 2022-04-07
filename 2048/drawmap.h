#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <graphics.h>
void drawmap(int map[6][6])
{
    IMAGE hover;
    IMAGE image;
    loadimage(&image, _T("./image/main.png"));
    putimage(0, 200, &image);
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (map[i][j] == 2)
            {
                loadimage(&hover, _T("./image/2.png"));
                putimage(10*j+100* (j-1), 200+i*10+100 * (i-1), &hover);
            }
            if (map[i][j] == 4)
            {
                loadimage(&hover, _T("./image/4.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 8)
            {
                loadimage(&hover, _T("./image/8.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 16)
            {
                loadimage(&hover, _T("./image/16.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 32)
            {
                loadimage(&hover, _T("./image/32.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 64)
            {
                loadimage(&hover, _T("./image/64.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 128)
            {
                loadimage(&hover, _T("./image/128.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 256)
            {
                loadimage(&hover, _T("./image/256.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 512)
            {
                loadimage(&hover, _T("./image/512.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 1024)
            {
                loadimage(&hover, _T("./image/1024.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
            if (map[i][j] == 2048)
            {
                loadimage(&image, _T("./image/2048.png"));
                putimage(10 * j + 100 * (j - 1), 200 + i * 10 + 100 * (i - 1), &hover);
            }
        }
    }
}
