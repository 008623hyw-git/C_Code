#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//读取空格版本的字符串逆序
int main() {
	char arr[10001] = { 0 };
	fgets(arr, sizeof(arr), stdin);//该代码会读取回车
	int len = strlen(arr);
	if (arr[len - 1] == '\n') {
		arr[len-1] = '\0';//清除回车
		len--;//整个字符串减去1
	}
	//scanf("%s", arr);//无法读取回车
	int left = 0;
	int right = len - 1;
	while (left < right) {
		char tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	printf("%s\n", arr);
	return 0;
}