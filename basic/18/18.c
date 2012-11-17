#include <stdio.h>
#include "func.h"
	
void main(void)
{
	char *s = "call echo()";
	extern int n;
	
	printf("call add() : %d\n", add(10, 20));
	echo(s);
	
	printf("before %d\n", n);
	n += 10;
	printf("after %d\n", n);
}