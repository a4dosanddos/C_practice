#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	char *cc;
	
	cc = (char *)malloc(12);
	if (cc == NULL) {
		printf("メモリが確保できません");
		exit(1);
	}
	strcpy(cc, "Hello World");

	printf("%s", cc);
}