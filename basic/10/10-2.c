#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	int *i;
	int n;
	
	i = (int *)calloc(10, sizeof(int));
	
	for(n = 1; n <= 10; n++) {
		*i = n;
		printf("%d ", *i);
		i++;
	} 
}