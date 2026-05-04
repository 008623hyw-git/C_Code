#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

//size_t my_strlen(const char* str) {
//	size_t count = 0;
//	assert(str);
//	while (*str != '\0') {
//		count++;
//		str++;
//	}
//	return count;
//}
//
//int main() {
//	char arr[] = "abcdef";
//	size_t len = my_strlen(arr);
//	printf("%u\n", len);
//	return 0;
//}

//char* my_strcpy(char* arr2,const char* arr1) {
//	assert(arr2 && arr1);
//	char* ret = arr2;
//	while (*arr2++ = *arr1++);
//	return ret;
//}
//int main() {
//	char source[] = "you are pig";
//	char arr[20] = { 0 };
//	my_strcpy(arr, source);//source传给arr1,arr传给arr2
//	printf("%s\n", arr);
//	return 0;
//}

//void my_strcat(char* word,const char* src) {
//	char* ret = word;
//	assert(word && src);
//	while (*word != '\0')
//		word++;//找到目标空间的末尾\0
//	while (*word++ = *src++);//拷贝字符串
//	return ret;
//}
//
//int main() {
//	char arr[20] = "hello ";
//	my_strcat(arr, "world");
//	printf("%s\n", arr);
//	return 0;
//}

int my_strcmp(const char* str1, const char* str2) {
	assert(str1 && str2);
	while (*str1 == *str2) {
		if (*str1 == '\0')
			return 0;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int main() {
	char arr[] = "zhangq";
	char arr1[] = "zhangsan";
	int ret = my_strcmp(arr, arr1);
	if (ret > 0)
		printf(">\n");
	else if (ret == 0)
		printf("=\n");
	else
		printf("<\n");
	return 0;
}