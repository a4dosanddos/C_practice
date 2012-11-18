#include <stdio.h>

int func(const void * a, const void * b);

void main(void)
{
	char s[80];
	int i, length;
	int j = 0;
	
	gets(s);
	length = strlen(s);
	
	printf("before : %s\n", s);
	qsort(s, length, sizeof(char), func);
	printf("after : %s\n", s);
	
	//eesstttt
	for(i = 1; i <= length; i++) {
		if(s[i] != s[i-1]) {
			printf("%c : %d\n", s[i-1], (i-j));
			j = i;
		}
	}
}

int func(const void * a, const void * b)
{
	if(*(char *)a > *(char *)b) {
		return 1;
	} else if(*(char *)a < *(char *)b) {
		return -1;
	} else {
		return 0;
	}
}