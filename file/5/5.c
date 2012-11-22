#include <stdio.h>


void main(void)
{
	FILE *f;
	unsigned char buf[256];
	
	if((f = fopen("test5.dat", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	while((fread(buf, 256, f)) != NULL) {
		printf("%s", s);
	}
}