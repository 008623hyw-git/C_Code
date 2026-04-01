#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a = 1;
	char* p = (char*)&a;
	if (*p)
		printf("Ð¡¶Ë\n");
	else
		printf("´ó¶Ë\n");
	return 0;
}