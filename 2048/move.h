#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstring>
extern int moveflag;
class Move
{
private:
public:
    void up();
    int judge(int map[6][6]);
    void down();
    void left();
    void right();
    void createfood();
    void score(int map);
    bool judgeleft(int map[6][6]);
    bool judgeright(int map[6][6]);
    bool judgeup(int map[6][6]);
    bool judgedown(int map[6][6]);
    int map[6][6] = { {0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} };
    int flag = 0;
    int curscore = 0;
};
void Move::up()
{
    if (Move::judge(map)==1) {
        flag = 1;
        return;
    }
    else if (Move::judge(map) == 2) return;
    for (int col = 1; col <= 4; col++) {
        for (int row = 1; row <= 4; row++) {
            if (!map[row][col]) {
                for (int k = row + 1; k <= 4; k++) {
                    if (map[k][col]) {
                        map[row][col] = map[k][col];
                        map[k][col] = 0;
                        break;
                    }
                }
            }
        }
        for (int row = 1; row <= 4; row++) {
            if (map[row][col] == map[row + 1][col]) {
                map[row][col] *= 2;
                Move::score(map[row][col]);
                if (map[row][col] == 2048) flag = 2;
                for (int k = row + 1; k <= 4; k++) {
                    map[k][col] = map[k + 1][col];
                    map[k + 1][col] = 0;
                }
            }
        }
    }
    Move::createfood();
}
void Move::down()
{
    if (Move::judge(map) == 1) {
        flag = 1;
        return;
    }
    else if (Move::judge(map) == 2) return;
    for (int col = 1; col <= 4; col++) {
        for (int row = 4; row >= 1; row--) {
            if (!map[row][col]) {
                for (int k = row - 1; k >= 1; k--) {
                    if (map[k][col]) {
                        map[row][col] = map[k][col];
                        map[k][col] = 0;
                        break;
                    }
                }
            }
        }
        for (int row = 4; row >= 1; row--) {
            if (map[row][col] == map[row - 1][col]) {
                map[row][col] *= 2;
                Move::score(map[row][col]);
                if (map[row][col] == 2048) flag = 2;
                for (int k = row - 1; k >= 1; k--) {
                    map[k][col] = map[k - 1][col];
                    map[k - 1][col] = 0;
                }
            }
        }
    }
    Move::createfood();
}
void Move::right()
{
    if (Move::judge(map) == 1) {
        flag = 1;
        return;
    }
    else if (Move::judge(map) == 2) return;
    for (int row = 1; row <= 4; row++) {
        for (int col = 4; col >= 1; col--) {
            if (!map[row][col]) {
                for (int k = col - 1; k >= 1; k--) {
                    if (map[row][k]) {
                        map[row][col] = map[row][k];
                        map[row][k] = 0;
                        break;
                    }
                }
            }
        }
        for (int col = 4; col >= 1; col--) {
            if (map[row][col] == map[row][col - 1]) {
                map[row][col] *= 2;
                Move::score(map[row][col]);
                if (map[row][col] == 2048) flag = 2;
                for (int k = col - 1; k >= 1; k--) {
                    map[row][k] = map[row][k - 1];
                    map[row][k - 1] = 0;
                }
            }
        }
    }
    Move::createfood();
}
void Move::left()
{
    if (Move::judge(map) == 1) {
        flag = 1;
        return;
    }
    else if (Move::judge(Move::map) == 2) return;
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= 4; col++) {
            if (!map[row][col]) {
                for (int k = col + 1; k <= 4; k++) {
                    if (map[row][k]) {
                        map[row][col] = map[row][k];
                        map[row][k] = 0;
                        break;
                    }
                }
            }
        }
        for (int col = 1; col <= 4; col++) {
            if (map[row][col] == map[row][col + 1]) {
                map[row][col] *= 2;
                Move::score(map[row][col]);
                if (map[row][col] == 2048) flag = 2;
                for (int k = col + 1; k <= 4; k++) {
                    map[row][k] = map[row][k + 1];
                    map[row][k + 1] = 0;
                }
            }
        }
    }
    Move::createfood();
}
void Move::createfood()
{
    srand(time(NULL));
    while (1)
    {
        int row = rand() % 4 + 1;
        int col = rand() % 4 + 1;
        if (!map[row][col])
        {
            int number = rand() % 2 + 1;
            map[row][col] = number * 2;
            break;
        }
    }
}
void Move::score(int map)
{
    if (map == 4) curscore += 10;
    else if (map == 8) curscore += 20;
    else if (map == 16) curscore += 40;
    else if (map == 32) curscore += 80;
    else if (map == 64) curscore += 160;
    else if (map == 128)curscore += 320;
    else if (map == 256)curscore += 640;
    else if (map == 512)curscore += 1280;
    else if (map == 1024)curscore += 2560;
    else if (map == 2048)curscore += 5120;
}
bool  Move::judgeleft(int map[6][6])
{
    for (int col = 1; col <= 3; col++) {
        for (int row = 1; row <= 4; row++)
        {
            if (!map[row][col]) return 0;
            if (map[row][col] == map[row][col + 1]) return 0;
        }
    }
    return true;
}
bool  Move::judgeup(int map[6][6])
{
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= 4; col++)
        {
            if (!map[row][col]) return 0;
            if (map[row][col] == map[row + 1][col]) return 0;
        }
    }
    return true;
}
bool  Move::judgeright(int map[6][6])
{
    for (int col = 4; col >= 2; col--) {
        for (int row = 1; row <= 4; row++)
        {
            if (!map[row][col]) return 0;
            if (map[row][col] == map[row][col - 1]) return 0;
        }
    }
    return true;
}
bool  Move::judgedown(int map[6][6])
{
    for (int row = 4; row >= 2; row--) {
        for (int col = 1; col <= 4; col++)
        {
            if (!map[row][col]) return 0;
            if (map[row][col] == map[row - 1][col]) return 0;
        }
    }
    return true;
}
int Move::judge(int map[6][6])
{
    if (moveflag == 1)
    {
        if (!Move::judgeup(Move::map)) return 0;
        if (!Move::judgeright(Move::map) || !Move::judgeleft(Move::map) || !Move::judgedown(Move::map)) return 2;
        else return 1;
    }
    if (moveflag == 2)
    {
        if (!Move::judgedown(Move::map)) return 0;
        if (!Move::judgeright(Move::map) || !Move::judgeleft(Move::map) || !Move::judgeup(Move::map)) return 2;
        else return 1;
    }
    if (moveflag == 3)
    {
        if (!Move::judgeleft(Move::map)) return 0;
        if (!Move::judgeright(Move::map) || !Move::judgedown(Move::map) || !Move::judgeup(Move::map)) return 2;
        else return 1;
    }
    if (moveflag == 4)
    {
        if (!Move::judgeright(Move::map)) return 0;
        if (!Move::judgeup(Move::map) || !Move::judgeleft(Move::map) || !Move::judgedown(Move::map)) return 2;
        else return 1;
    }
}