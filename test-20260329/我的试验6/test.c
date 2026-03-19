#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>

//int my_strlen(const char* str) {
//	int count = 0;
//	assert(str);
//	while (*str != '\0') {
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main() {
//	char arr[] = "HELLO BIT";
//	//char* arr = NULL;
//	printf("%d\n", my_strlen(arr));
//	return 0;
//}
int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	while (scanf("%d %d %d", &a, &b, &c) == 3) {
		if ((a + b > c) && (a + c > b) && (b + c) > a) {
			if (a == b && b == c)
				printf("等边三角形\n");
			else if ((a == b && b != c) || (a == c && a != b) || (b == c && b != a))
				printf("等腰三角形\n");
			else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
				printf("直角三角形\n");
			else
				printf("普通三角形\n");
		}
		else {
			printf("不是三角形\n");
		}
	}
	return 0;
}