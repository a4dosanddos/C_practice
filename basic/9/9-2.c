#include <stdio.h>

int func(const void * a, const void * b);

void main(void)
{
	int num[] = {1, 5, 7, 12, 17, 20, 22, 25, 29, 30};
	char ss[10];
	int i, in, length;
	int *result;
	
	length = sizeof num / sizeof num[0];
	
	printf("数字を入力してください ");
	gets(ss);
	in = atoi(ss);
	printf("%d\n", in);
	
	result = (int *)bsearch(&in, num, length, sizeof(int), func);
	if (result != NULL) {
		for(i = 0; i < length; i++) {
			if (num[i] == *result) {
				printf("入力された数字は要素 %d 番目にあります", i + 1);
			}
		}
	} else {
		printf("入力された数字は配列に含まれていません");
	}
}

int func(const void * a, const void * b)
{
	if(*(int *)a > *(int *)b) {
		return 1;
	} else if(*(int *)a < *(int *)b) {
		return -1;
	} else {
		return 0;
	}
}