#include <stdio.h>
	
void main(void)
{
	int num[] = {1, 5, 7, 12, 17, 20, 22, 25, 29, 30};
	char ss[10];
	int i, in, mid, left, right;
	
	left = 0;
	right = sizeof num / sizeof num[0];
	
	printf("数字を入力してください ");
	gets(ss);
	in = atoi(ss);
	printf("%d\n", in);
	
	while (left <= right) {
		mid = (left + right) / 2;
		if (num[mid] == in) {
			printf("入力した数は %d 番目の要素にあります", mid + 1);
			return;
		} else if (num[mid] > in) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	printf("入力した要素はありません");
}