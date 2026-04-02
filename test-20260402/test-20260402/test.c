#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	const char* p1 = "abcdef";
	const char* p2 = "abcdef";//abcdef是常量，只能读不能取，p1和p2类容一样，因此两个指向同一个空间
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";//arr1和arr2创建的时候开辟了两个不同的空间,arr和p都是放的首元素的地址
	if (p1 == p2)
		printf("p1=p2\n");//结果1
	else
		printf("p1!=p2\n");
	if (arr1 == arr2)
		printf("arr1=arr2\n");
	else
		printf("arr1!=arr2\n");//结果2
	return 0;
}