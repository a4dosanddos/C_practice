#include <stdio.h>

int func(const void * a, const void * b);

void main(void)
{
	int num[] = {5, 60, 50, 80, 1, 15, 70, 100, 35, 20};
	//char *fruit[] = {"orange", "apple", "melon", "mango", "pineapple", "strawberry", "peach", "kiwi", "pear", "cherry"};
	int length;
	int i;
	
	length = sizeof num / sizeof num[0];
	
	//void qsort( void *base, size_t n, size_t size, int (*func)( const void *c1, const void *c2 ) )
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