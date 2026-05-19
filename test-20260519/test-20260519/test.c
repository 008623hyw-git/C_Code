#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t num) {
	assert(dest && src);
	void* ret = dest;
	while (num--) {
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

int main() {
	int arr1[] = { 1,2,3,4,5,6,7};
	int arr2[10] = { 0 };
	my_memcpy(arr2, arr1, 28);
	int sz=sizeof(arr2)/sizeof(arr2[0]);
	for (int n = 0; n < sz; n++)
		printf("%d ", arr2[n]);
	return 0;
}