#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cmp_int(const void* e1, const void* e2) {
	return (*(int*)e1 - *(int*)e2);//降序只需要交换e1和e2即可
}

int main() {
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);//库函数qsort(要排序数据的起始位置【也就是数组的地址】，待排序数据的元素个数，单个带排序数据的元素大小[字节]，函数指针--比较数据);
	int i = 0;
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	return 0;
}