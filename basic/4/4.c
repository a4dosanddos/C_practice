#include <stdio.h>
#include <stdlib.h>
	
#define NUM_STR 6

void main(void)
{
	int i;
	time_t timer;
	int result;
	
	time(&timer);
	srand(timer);
	
	for(i = 0; i < 5; i++) {
		result = rand() % NUM_STR + 1;
		printf("%d\n",result);
	}
}