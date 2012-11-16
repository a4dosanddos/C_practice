#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	char *cc;
	
	cc = (char *)malloc(12);
	if (cc == NULL) {
		printf("ƒƒ‚ƒŠ‚ªŠm•Û‚Å‚«‚Ü‚¹‚ñ");
		exit(1);
	}
	strcpy(cc, "Hello World");

	printf("%s", cc);
}