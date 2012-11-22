#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	FILE *f;
	char s[80];
	
	printf("文字列を入力してください : ");gets(s);
	
	if((f = fopen("test.txt", "w")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	fputs(s, f);
	printf("ファイルへの出力が完了しました");
	
	fclose(f);
}