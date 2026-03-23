#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//求最小公倍数
int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	//方法1：暴力求解
	//int m = (a > b ? a : b);    //最大公因数：将>改成<
	//while (1) {
	//	if (m % a == 0 && m % b == 0)    //最大公因数：将两个式子中的被除数和除数交换
	//		break;
	//	m++;    //最大公因数：m--;
	//}
	//printf("%d\n", m);
	//方法2
	int i = 1;
	while (a * i % b)
		i++;
	printf("%d", i * a);
	return 0;
}