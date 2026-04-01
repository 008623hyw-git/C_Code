#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

void move_odd_even(int arr[], int sz) {
	int left = 0;
	int right = sz - 1;
	while (left < right) {
		while (left % 2 == 1)//从左到右找偶数，找到了就停下
			left++;
		while (right % 2 == 0)//从右向左找奇数，找到了就停下
			right--;
		if (left < right) {
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
	}
}

int main(){
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < sz; i++) {
		scanf("%d", arr + i);
	}
	move_odd_even(arr, sz);

	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}