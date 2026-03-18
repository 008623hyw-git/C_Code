#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j]=' ';//棋子（空格）
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;//打印数据
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|");//分割列
		}
		printf("\n");
		if (i < row - 1) {
			int j = 0;//分割行
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void Player(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		printf("玩家下棋，请输入坐标>：");
		scanf("%d %d", &x, &y);
		if (x>=1&&x<=row&&y>=1&&y<= col) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用，重新输入\n");
			}
		}
		else {
			printf("超出坐标范围，请重新输入\n");
		}
	}
}

void Computer(char board[ROW][COL], int row, int col) {
	printf("电脑正在思考中\n");
	Sleep(1000);
	printf("电脑下棋：\n");
	int x = 0;
	int y = 0;
	while (1) {
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col) { 
	int i = 0;
	int j = 0;//满了返回1，没满返回0
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col) {
	int i = 0;//判断行
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			if (board[i][0] != board[i][j]) {
				break;
			}
		}
		if (j == col && board[i][0] != ' ') {
			return board[i][0];
		}

	}
	int j = 0;//判断列
	for (j = 0; j < col; j++) {
		int i = 0;
		for (i = 0; i < row; i++) {
			if (board[0][j] != board[i][j])
				break;
		}
		if (i == row && board[0][j] != ' ') {
			return board[0][j];
		}
	}
	if (col >= row){//判断从左上角到右下角的对角线
		for (i = 0; i < col-row+1; i++) {
			int j = 0;
			for (j = 0; j < row; j++) {//小于row是限制对角线的最大长度
				if (board[0][0+i] != board[j][j+i])
					break;
			}
			if (j == row && board[0][0+i] != ' ')
				return board[0][0+i];
		}
	}
	if (row > col) {
		for (i = 0; i < row - col + 1; i++) {
			int j = 0;
			for (j = 0; j < col; j++) {
				if (board[0+i][0] != board[j+i][j])
					break;
			}
			if (j == col && board[0+i][0] != ' ')
				return board[0+i][0];
		}
	}
	if (col >= row) {//判断从右上角到左下角的对角线
		for (i = 0; i < col - row + 1; i++) {
			int j = 0;
			for (j = row; j>0; j--) {
				if (board[0][i+row-1] != board[row-j][i+j-1])
					break;
			}
			if (j == 0 && board[0][i - 1 + row] != ' ')
				return board[0][i+row-1];
		}
	}
	if (row>col) {
		for (i = 0; i < row - col + 1; i++) {
			int j = 0;
			for (j = col; j > 0; j--) {
				if (board[i + col - 1][0] != board[i + j - 1][col-j])
					break;
			}
			if (j == 0 && board[i + col - 1][0] != ' ')
				return board[i + col - 1][0];
		}
	}
	if (IsFull(board, row, col)) {
		return 'Q';
	}
	return 'C';
}
//每次写函数前，必须现在头文件声明这个函数，否则编辑器会默认该函数为int类型。判断行和列的思路是：利用循环不断变化的i和j的下标跟第一个字符比较