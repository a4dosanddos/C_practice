#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	char *cc;
	
	cc = (char *)malloc(12);
	if (cc == NULL) {
		printf("���������m�ۂł��܂���");
		exit(1);
	}
	strcpy(cc, "Hello World");

	printf("%s", cc);
}