#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("------------------\n");
	printf("|     1.开始     |\n");
	printf("|     2.退出     |\n");
	printf("------------------\n");
}

void game() {
	char ret = 0;
	printf("三子棋，开始：\n");
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	int d = rand() % 100;
	if (d < 50&&d>=0){
		printf("玩家先下\n");
		while (1) {
			Player(board, ROW, COL);//玩家下棋
			ret = IsWin(board, ROW, COL);
			if (ret != 'C') {
				break;
			}
			DisplayBoard(board, ROW, COL);
			Computer(board, ROW, COL);//电脑下棋
			ret = IsWin(board, ROW, COL);
			if (ret != 'C') {
				break;
			}
			DisplayBoard(board, ROW, COL);
		}
	}
	else {
		printf("电脑先下\n");
		while (1) {
			Computer(board, ROW, COL);//电脑下棋
			ret = IsWin(board, ROW, COL);
			if (ret != 'C') {
				break;
			}
			DisplayBoard(board, ROW, COL);
			Player(board, ROW, COL);//玩家下棋
			ret = IsWin(board, ROW, COL);
			if (ret != 'C') {
				break;
			}
			DisplayBoard(board, ROW, COL);
		}
	}
	if (ret == '*') {
		printf("游戏结束，你赢了\n");//玩家赢
	}
	else if (ret == '#') {
		printf("GAME OVER!\n");//电脑赢
	}
	else {
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
	}
int main() {
	srand((unsigned int)time(NULL));
	int input = 0;
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input) {
		case 1: {
			game();
			break;
		}
		case 2: {
			printf("退出游戏\n");
			return 0;
		}
		default: {
			printf("选择错误，请重新选择\n");
			break;
		}
		}
	} while (input);
	return 0;
}