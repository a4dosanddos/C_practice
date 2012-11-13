#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	time_t timer;
	
	time(&timer);
	
	printf("%s\n", ctime(&timer));
}