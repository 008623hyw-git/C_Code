#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Stu {
	char name[20];
	int age;
};

int cmp_int(const void* e1,const void* e2) {
	return (*(int*)e1 - *(int*)e2);
}

int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

void Swap(char* buf1, char* buf2, int width) {
	int i = 0;
	for (i = 0; i < width; i++) {
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width,int (*cmp)(const void* e1,const void* e2)) {
	int i = 0;
	for (i = 0; i < sz-1; i++) {
		int flag = 1;
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
				Swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}

void test3() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}

void test4() {
	struct Stu s[] = { {"zhangsan",15},{"lisi",30},{"wangwu",45} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s,sz,sizeof(s[0]),cmp_stu_by_age);
}

int main() {
	test3();
	return 0;
}