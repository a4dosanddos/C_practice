#include <stdio.h>
#include <stdlib.h>

#define ENTER 13
#define MEMSIZE (1024 * 1000)
		
void main(void)
{
	int n;
	int i = 1;
	char *p;
	
	p = (char *)malloc(0);
	
	while ((n = getch()) == 13) {
		p = (char *)realloc(p, MEMSIZE * i);
		printf("%d\n", _msize(p));
		i++;
	} 
}