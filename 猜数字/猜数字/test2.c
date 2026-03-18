#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void menu() {
	printf("************\n");
	printf("***1.开始**\n");
	printf("***2.退出***\n");
	printf("************\n");//用void函数是因为不会返回这个函数
}
void game() {
	RAND_MAX;//0x的意思是16进制，随机范围范围在0-32767，选中然后鼠标右键并单击“转到定义”查看定义，其实这个代码可忽略不写
	int guess = 0;
	int ran = rand()%100+1;//属于头文件stdlib.h,范围为1到100
	while (ran) {
		printf("游戏开始，猜数字>");
		scanf("%d", &guess);
		if (guess < ran) {
			printf("猜小了，再来\n");
		}
		else if (guess > ran) {
			printf("猜大了，再来\n");
		}
		else {
			printf("恭喜你猜对了！！\n");
			break;
		}
	}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//调用rand之前，使用函数srand去设置生成随机数的生成器；unsigned是强制性转换数据类型的工具，将time_t转换成int数据类型；NULL为空指针
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