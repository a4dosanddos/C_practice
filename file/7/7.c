#include <stdio.h>
#include <string.h>
	
void main(void)
{
	FILE *f1, *fo, *f2;
	unsigned char buf1[256], wk1[256], buf2[256], wk2[256];
	int i, size1, size2;
	unsigned char xor = 255;
	//printf("%d", xor);
	//return;
	if((f1 = fopen("test7.txt", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	size1 = fread(buf1, sizeof(unsigned char), 256, f1);
	fclose(f1);
	
	printf("-----");
	for(i = 0; i <size1; i++) {
		if(i % 16 == 0) printf("\n");
		printf("%x", buf1[i]);
	}
	printf("\n-----\n");
	
	memset(wk1, '\0', 256);
	for(i = 0; i < size1; i++) {
		wk1[i] = buf1[i]^xor;
	}
	
	if((fo = fopen("output.txt", "wb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	fputs(wk1, fo);
	fclose(fo);
	
	if((f2 = fopen("output.txt", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	size2 = fread(buf2, sizeof(unsigned char), 256, f2);
	fclose(f2);
	
	memset(wk2, '\0', 256);
	for(i = 0; i < size2; i++) {
		wk2[i] = buf2[i]^xor;
	}
	
	printf("復号 : %s", wk2);
}