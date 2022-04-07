#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
class Move
{
private:
public:
    void up();
    void down();
    void left();
    void right();
    void createfood();
    bool judge();
    int map[6][6] = { 0 };
    int flag = 0;
};
void Move::up()
{
    if (Move::judge()) {
        flag = 1;
        return;
    }
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
    if (Move::judge()) {
        flag = 1;
        return;
    }
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
    if (Move::judge()) {
        flag = 1;
        return;
    }
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
    if (Move::judge()) {
        flag = 1;
        return;
    }
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
bool Move::judge()
{
    for (int row = 1; row <= 4; row++) {
        for (int col = 1; col <= 4; col++)
        {
            if (!map[row][col]) return false;
            if (map[row][col] == map[row + 1][col]) return false;
            if (map[row][col] == map[row][col + 1]) return false;
        }
    }
    return true;
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
