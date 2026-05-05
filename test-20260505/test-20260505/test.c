#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
//strncmp的应用
//int main() {
//	char arr1[] = "abc";
//	char arr2[] = "abcdef";
//	int ret = strncmp(arr1, arr2,3);
//	printf("%d\n", ret);
//	if (ret == 0)
//		printf("==\n");
//	else if (ret > 0)
//		printf(">\n");
//	else
//		printf("<\n");
//	return 0;
//}

//模拟strstr函数
char* my_strstr(char* str1, char* str2) {
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p) {//*p不等于'\0'就进入循环
		s1 = p;
		s2 = str2;//每次开始匹配前被赋值s2
		while (*s1!='\0'&&*s2!='\0'&& * s1 == *s2) {
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (char*)p;
		p++;
	}
	return NULL;
}

int main() {
	char email[] = "abc";
	char substr[] = "abc";
	char* ret = my_strstr(email, substr);
	if (ret == NULL)
		printf("子串不存在\n");
	else
		printf("%s\n", ret);
	return 0;
}