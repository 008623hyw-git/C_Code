#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Test {
	int Num;
	char* pcName;
	short sDate;
	char cha[2];
	short sBa[4];
}*p = (struct Test*)0x100000;
int main() {
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a+ 1);
	int a1[5][5];
	int(*p1)[4];
	p1 = a1;
	printf("%d %d\n", *(a + 1), *(ptr1 - 1));
	printf("%p\n", p + 0x1);
	printf("%p\n", (unsigned long)p + 0x1);
	printf("%p\n", (unsigned int*)p + 0x1);
	printf("%x %x\n", ptr1[-1],*ptr2);
	printf("%p,%d\n", &p1[4][2] - &a1[4][2], &p1[4][2] - &a1[4][2]);
	return 0;
}