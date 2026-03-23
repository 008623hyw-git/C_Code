#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

void reverse(char* left,char* right) {
	assert(left);
	assert(right);
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main() {
	char arr[101] = { 0 };
	fgets(arr, sizeof(arr), stdin);
	int len = strlen(arr);
	if (arr[len - 1] == '\n') {
		arr[len - 1] = '\0';
		len--;
	}
	int left = 0;
	int right = len - 1;
	reverse(arr, arr + len - 1);
	char* start = arr;
	while (*start) {
		char* end = start;
		while (*end != ' '&&*end!='\0') {
			end++;
		}
		reverse(start, end - 1);
		if(*end!='\0')
			end++;
		start = end;
	}
	printf("%s", arr);
	return 0;
}