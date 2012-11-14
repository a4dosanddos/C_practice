#include <stdio.h>

int func(const void * a, const void * b);

void main(void)
{
	char *fruit[] = {"orange", "apple", "melon", "mango", "pineapple", "strawberry", "peach", "kiwi", "pear", "cherry"};
	int length;
	int i;
	
	length = sizeof fruit / sizeof *fruit;
	
	qsort(num, length, sizeof(num[0]), func);
	
	for(i = 0; i < length; i++) {
		printf("%d ", num[i]);
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