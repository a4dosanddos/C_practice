#include <stdio.h>

typedef struct File {
	int data_size;
	int file_size;
	unsigned char file_name[256];
	unsigned char data[256];
} file;

void amethod(char **argv);
void xmethod(char **argv);

void main(int argc, char *argv[])
{
	if(strcmp(argv[1], "/a") == 0) {
		amethod(argv);
	} else if(strcmp(argv[1], "/x") == 0) {
		xmethod(argv);
	} else {
		printf("/a、/x 以外のオプションはありません");
	}
}

// ファイルの結合
void amethod(char **argv)
{
	FILE *ff, *f1, *f2, *f3;
	int i;
	file f[3];
	
	if((f1 = fopen(argv[3], "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	if((f2 = fopen(argv[4], "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	if((f3 = fopen(argv[5], "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	f[0].data_size = fread(f[0].data, sizeof(unsigned char), 256, f1);
	f[1].data_size = fread(f[1].data, sizeof(unsigned char), 256, f2);
	f[2].data_size = fread(f[2].data, sizeof(unsigned char), 256, f3);
	
	for(i = 0; i < 3; i++) {
		f[i].file_size = strlen(argv[i+3]);
	}
	
	if((ff = fopen(argv[2], "wb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	for(i = 0; i < 3; i++) {
		fwrite(&(f[i].data_size), sizeof(int), 1, ff);
		fwrite(&(f[i].file_size), sizeof(int), 1, ff);
		fwrite(argv[i+3], sizeof(unsigned char), strlen(argv[i+3]), ff);
		fwrite(f[i].data, sizeof(unsigned char), f[i].data_size, ff);
	}
	
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(ff);
}

// ファイルの分割
void xmethod(char **argv)
{
	FILE *f, *f1, *f2;
	char buf[500];
	int i, j, size;
	int data_size = 0;
	int file_size = 0;
	char file_name[256];
	char data[500];
	
	memset(file_name, '\0', 256);
	memset(data, '\0', 500);
	
	if((f = fopen(argv[2], "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	size = fread(buf, sizeof(unsigned char), 500, f);
	
	// データサイズ
	for(i = 0; i < 4; i++) {
		data_size += (int)buf[i];
	}
	// ファイルサイズ
	for(i; i < 8; i++) {
		file_size += (int)buf[i];
	}
	// ファイル名
	for(j = 0; j < file_size; i++, j++) {
		file_name[j] = buf[i];
	}
	// データ
	for(j = 0; j < data_size; i++, j++) {
		data[j] = buf[i];
	}
	/*printf("データの長さ     : %d\n", data_size);
	printf("ファイル名の長さ : %d\n", file_size);
	printf("ファイル名       : %s\n", file_name);
	printf("データ           : %s\n", data);*/
	
	if((f1 = fopen(file_name, "w")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	fwrite(data, sizeof(unsigned char), data_size, f1);
	fclose(f1);
	
	data_size = 0;
	file_size = 0;
	memset(file_name, '\0', 256);
	memset(data, '\0', 500);
	
	
	// データサイズ
	for(; i < 34; i++) {
		data_size += (int)buf[i];
	}
	// ファイルサイズ
	for(; i < 38; i++) {
		file_size += (int)buf[i];
	}
	// ファイル名
	for(j = 0; j < file_size+30; i++, j++) {
		file_name[j] = buf[i];
	}
	// データ
	for(j = 0; j < data_size+30; i++, j++) {
		data[j] = buf[i];
	}
	printf("データの長さ     : %d\n", data_size);
	printf("ファイル名の長さ : %d\n", file_size);
	printf("ファイル名       : %s\n", file_name);
	printf("データ           : %s\n", data);
	
	if((f2 = fopen(file_name, "w")) == NULL) {
		printf("ファイルのオープンに失敗しました3");
		exit(1);
	}
	fwrite(data, sizeof(unsigned char), data_size, f2);
	fclose(f2);
	
	fclose(f);
}

// データ構造を決める
// データ部の長さ 4バイト ● size1
// ファイル名の長さ 4バイト
// ファイル名
// データ ● buf1