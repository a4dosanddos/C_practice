#include <stdio.h>
#include <stdlib.h>
	
void main(int argc, char *argv[])
{
	FILE *f;
	char ss[256];
	
	if(argc == 1) {
		printf("パスを入力してください");
		exit(1);
	}
		
	if((f = fopen(argv[1], "r")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	while(fgets(ss, 256, f) != NULL) {
		printf("%s", ss);
	}
	
	fclose(f);
}