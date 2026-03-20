#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	/*int a = 0;
	int n = 0;
	int sum = 0;
	int i = 0;
	int j = 0;
	scanf("%d %d", &a, &j);
	for (i = 0; i < j; i++) {
		n = n * 10 + a;
		sum += n;
	}
	printf("%d", sum);*/
	int line = 0;
	int i = 0;
	scanf("%d", &line);
	for (i = 0; i < line; i++) {
		int j = 0;
		for (j = 0; j < line - 1 - i; j++)
			printf(" ");
		for (j = 0; j < (2 * i) + 1; j++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i < line - 1; i++) {
		int j = 0;
		for (j = 0; j < i + 1; j++)
			printf(" ");
		for (j = 0; j < 2*(line-1-i)-1;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}