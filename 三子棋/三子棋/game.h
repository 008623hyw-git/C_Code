#pragma once//游戏代码的声明
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);//打印棋盘
void Player(char board[ROW][COL], int row, int col);//玩家下棋
void Computer(char board[ROW][COL], int row, int col);//电脑下棋
char IsWin(char board[ROW][COL], int row, int col);

