#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("--------------\n");
	printf("|   1.play   |\n");
	printf("|   2.exit   |\n");
	printf("--------------\n");
}

void game() {
	char mine[ROWS][COLS] = {0};//存放布置好的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出雷的信息
	Initboard(mine, ROWS, COLS,'0');//数组没有布置雷的时候，都是0
	Initboard(show, ROWS, COLS,'#');//数组没有排查雷的时候，都是#，盖住整个场地
	SetMine(mine, ROW, COL);
	Displayboard(show, ROW, COL);//隐藏地雷
	//Displayboard(mine, ROW, COL);//打开埋雷的位置
	FindMine(mine,show,ROW,COL);  //排查雷
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));
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
			printf("游戏程序已经关闭\n");
			return 0;
		}
		default: {
			printf("无效选项，请重新选择\n");
			break;
			}
		}
	} while (input);
	return 0;
}