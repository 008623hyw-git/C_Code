#pragma once
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ROW 9  //排雷场地宽
#define COL 9 //排雷场地长
#define ROWS ROW+2
#define COLS COL+2
#define MINE_COUNT 10//埋的地雷数量
void Initboard(char board[ROWS][COLS], int rows, int cols,char set);
void Displayboard(char board[ROWS][COLS], int row, int col);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//展开函数