#include <stdio.h>

typedef struct USER {
	char id[2];
	char name[5];
	int num;
} user;

void main(void)
{
	FILE *f;
	unsigned char buf[500];
	int i, size;
	
	if((f = fopen("test6.dat", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	size = fread(buf, sizeof(unsigned char), 500, f);
	
	printf("バイナリファイルの内容\n-----");
	for(i = 0; i < size; i++) {
		if(i % 16 ==0) printf("\n");
		printf("%x", buf[i]);
	}
	printf("\n");
	printf("-----\n");
}