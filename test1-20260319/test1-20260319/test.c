#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//int arr[] = { 1,2,3,4,5 };
	//short* p = (short*)arr;
	//int i = 0;
	//for (i = 0; i < 4; i++)
	//	*(p + i) = 0;//[00(01) 00 00 00] [00(02) 00 00 00] [03 00 00 00] [04 00 00 00] [05 00 00 00]
	//for (i = 0; i < 5; i++)
	//	printf("%d ", arr[i]);//解引用时，short*一次性访问两个字节，而一个整形是4个字节，因此只有两个数字变成了0


	int a = 0x11223344;//内存中的存放:44 33 22 11
	char* pc = (char*)&a;//解引用时候访问1一个字节
	*pc = 0;//*pc指向第一个字节44
	printf("%x\n", a);//结果：11223300
	return 0;
}