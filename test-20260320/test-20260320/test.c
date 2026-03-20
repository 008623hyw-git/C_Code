#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
   /* int a = 0;//´òÓ¡2+22+222+2222+22222µÄÖµ
    int n = 0;
    int sum = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d", &a,&j);
    for (i = 0; i < j; i++) {
        n = n * 10 + a;
        sum += n;
    }
        printf("%d", sum);*/
    int i = 0;
    int n = 0;
    scanf("%d", &n);
    int x = (n + 1) / 2;
    for (i = 0; i < x; i++) {
        int j = 0;
        for (j = 0; j < x-i-1; j++)
            printf(" ");
        for (j = 0; j < (i * 2 + 1); j++)
            printf("*");
        for (j = 0; j < x -i- 1; j++)
            printf(" ");
        printf("\n");
    }
    for (i = 0; i < n - x; i++) {
        int j = 0;
        for (j = 0; j < i + 1; j++)
            printf(" ");
        for (j = 0; j < n - 2 * (i + 1); j++)
            printf("*");
        for (j = 0; j < i + 1; j++)
            printf(" ");
        printf("\n");
    }
    return 0;
}