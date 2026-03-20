#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//喝汽水，1瓶汽水一块钱，两个空瓶可以换一瓶汽水
int main() {
	int money = 0;
	scanf("%d", &money);
	int total = money;
	int empty = money;
	while (empty>=2){
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d", total);
	/*if (money > 0)
		printf("%d", 2 * money - 1);
	else
		printf("%d", 0);*/
	
	return 0;
}	