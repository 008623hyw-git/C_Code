#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols,char set) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col) {  //意思是传过来的是11×11的数组，用的是9×9的数组
	int i = 0;
	int j = 0;
	printf("----<扫雷>----\n");
	printf("    ");//列号之前的空格
	for (j = 1; j <= col; j++) {
		printf("%d ", j);//打印列号,忽略0
	}
	printf("\n");
	for (j = 0; j <= 2*col+3; j++) {
		printf("-");
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%2d |", i);//打印行号
		for (j = 1; j <= col; j++) {
			printf("%c ", board[i][j]);
		}
		printf("|\n");
	}
	for (j = 0; j <= 2*col+3; j++) {
		printf("-");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int row, int col) {//布置地雷
	int count = MINE_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0'){  //如果这里没有放雷
			board[x][y] = '*';
			count--;
		}
	}
}

int get_mine_count(char board[ROWS][COLS], int x, int y) {//计算这个格子周围的地雷数量
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			if (board[x + i][y + j] == '*')
				count++;
		}
	}
	return count;
}

void spread(char mine[ROWS][COLS], char show[ROWS][COLS],int x ,int y) {//展开条件，该坐标不是雷，该坐标周围没有雷*，周围没有被排查过
	int i = 0;
	int j = 0;
	if(x>0&&x<ROWS-1&&y>0&&y<COLS-1) {//输入范围是为了防止排查没有出现在地图上的格子
		for (i = -1; i <= 1; i++) {
			for (j = -1; j <= 1; j++) {
				if (x+i < 0 || x+i >= ROWS || y+j < 0 || y+j >= COLS)
					continue;//AI修正，避免死递归
				if (show[x + i][y + j] == '#'&& show[x][y] == '0') {//尝试判断周围有没有被排查过，并且周围没有雷
					show[x + i][y + j] = get_mine_count(mine, x + i, y + j) + '0';//该坐标周围的数字被打印出来
					spread(mine, show, x + i, y + j);//如果展开的数字出现0，以这个0为中心继续展开
				}
			}
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int a = 0;
	int b = 0;
	int r = 0;
	int s = 0;
	int mine_count = MINE_COUNT;
	printf("该地图上有%d个地雷\n", MINE_COUNT);
	printf("游戏开始，选项1排雷，选项2插旗或移除\n");
	while (1) {
		int i = 0;
		printf("选项:");
		scanf("%d", &i);
		switch (i) {
			case 1: {
				printf("开始排雷，请输入坐标>");
				while (1) {
					scanf("%d %d", &x, &y);
					if (x >= 1 && x <= row && y >= 1 && y <= col) {
						if (show[x][y] != '#') {
							printf("你已经排查了该位置，请重新寻找另一个目标\n");
							printf("继续排雷，请输入坐标>");
						}
						else {
							if (mine[x][y] == '*') {
								printf("boom!你被炸死了\n");//踩雷了
								Displayboard(mine, ROW, COL);
								return;
							}
							else {
								int g_count = 0;//计算地图上除了P和#外剩下被排查的格子的数量
								int count = get_mine_count(mine, x, y);//没有被炸死，显示周围有多少个雷
								show[x][y] = count + '0';//将输出转换成字符形式
								spread(mine, show, x, y);
								Displayboard(show, ROW, COL);//显示执行结果
								for (r = 1; r <= ROW; r++) {
									for (s = 1; s <= COL; s++) {
										if (show[r][s] != '#'&&show[r][s]!='P')
											g_count++;//判断地图上被翻开格子的数量
									}
								}
								if (g_count == COL * ROW - MINE_COUNT) {//当场上的数字等于所有格子减去地雷数量时
									printf("安全区域排查完毕，扫雷完成\n");
									Displayboard(mine, ROW, COL);
									return;
								}
								printf("继续游戏，选项1排雷，选项2插入或移除旗子\n");
								break;
							}
						}
					}
					else {
						printf("超出场地范围，重新输入\n");//1
						printf("继续排雷，请输入坐标>");
					}
				}
				break;
			}
			case 2: {
				while (1) {
					printf("移除或安插旗子>");
					scanf("%d %d", &a, &b);
					if (a < ROWS && a>0 && b < COLS && b>0) {
						if (show[a][b] != '#' && show[a][b] != 'P')
							printf("这个格子被排查过了，换一个\n");
						else {
							if (show[a][b] == '#') {
								show[a][b] = 'P';
								if (mine[a][b] == '*') {
									printf("找到一个地雷\n");
									mine_count--;
									printf("地雷剩下%d个\n", mine_count);
									printf("\n");
								}
								Displayboard(show, ROW, COL);
							}
							else if (show[a][b] == 'P') {
								show[a][b] = '#';
								if (mine[a][b] == '*') {
									printf("这里是地雷哦!\n");
									printf("请把旗子插回去\n");
									mine_count++;
									continue;
								}
								Displayboard(show, ROW, COL);
							}
							if (mine_count == 0) {//地雷全部被发现
								printf("安全区域排查完毕，扫雷完成\n");
								Displayboard(mine, ROW, COL);
								return;
							}
							printf("继续游戏，选项1排雷，选项2插入或移除旗子\n");
							break;
						}
					}
					else
						printf("提示：操作必须在该地图内\n");
				}
				break;
			}
			default: {
				printf("选项无效\n");
				break;
			}
		}
	}
}