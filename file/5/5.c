#include <stdio.h>


void main(void)
{
	FILE *f;
	unsigned char buf[256];
	int i, j, size;
	int data_size = 0;
	int file_size = 0;
	char file_name[8];
	char data[10];
	
	if((f = fopen("test5.dat", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	size = fread(buf, sizeof(unsigned char), 256, f);
	
	// とりあえず表示してみる
	printf("バイナリファイルの内容\n-----");
	for(i = 0; i < size; i++) {
		// 見やすいように改行を入れる
		if(i % 16 == 0) printf("\n");
			printf("%X", buf[i]);
	}
	printf("\n");
	printf("-----\n");
	
	// データサイズ
	for(i = 0; i < 4; i++) {
		data_size += (int)buf[i];
	}
	// ファイルサイズ
	for(i = 4; i < 8; i++) {
		file_size += (int)buf[i];
	}
	// ファイル名
	for(i = 8, j = 0; j < file_size; i++, j++) {
		file_name[j] = buf[i];
	}
	// データ
	for(i = 16, j = 0; j < data_size; i++, j++) {
		data[j] = buf[i];
	}
	printf("データの長さ     : %d\n", data_size);
	printf("ファイル名の長さ : %d\n", file_size);
	printf("ファイル名       : %s\n", file_name);
	printf("データ           : %s\n", data);
}
