#include <stdio.h>
#include <stdlib.h>

int func(const void * a, const void * b);

typedef struct TestStruct {
	char str[100];
	short order;
} teststruct;

void main(void)
{
	teststruct t[5];
	int i,length;
	time_t timer;
	
	time(&timer);
	srand(timer);
	
	printf("before\n");
	for(i = 0; i < 5; i++) {
		strcpy(t[i].str,"abcde");
		t[i].order = rand();
		printf("%s ",t[i].str);
		printf("%d\n",t[i].order);
	}
	length = sizeof t / sizeof t[0];
	//printf("%d ",length);
	
	qsort(t, length, sizeof(teststruct), func);
	
	printf("after\n");
	for(i=0;i<length;i++) {
		printf("%s ",t[i].str);
		printf("%d\n",t[i].order);
	}
}

int func(const void * a, const void * b)
{
	if(((teststruct *)a)->order > ((teststruct *)b)->order) {
		return 1;
	} else if(((teststruct *)a)->order < ((teststruct *)b)->order) {
		return -1;
	} else {
		return 0;
	}
}