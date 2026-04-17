#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Add(int x, int y) {
	return x + y;
}

int Min(int x, int y) {
	return x - y;
}

int Mul(int x, int y) {
	return x * y;
}

int Div(int x, int y) {
	return x / y;
}

void cal(int(*pf)(int,int)) {
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("输入两个操作数：");
	scanf("%d %d", &x, &y);
	ret = pf(x, y);
	printf("%d\n", ret);
}
int main() {
	int input = 0;
	do {
		printf("计算开始:1.add 2.minus 3.multipile 4.divide\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			cal(Add);
			break;
		case 2:
			cal(Min);
			break;
		case 3:
			cal(Mul);
			break;
		case 4:
			cal(Div);
			break;
		case 0:
			printf("退出计算器\n");
			return 0;
		default:
			printf("无效选择\n");
		}
	} while (input);
	return 0;
}