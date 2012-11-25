#include <stdio.h>

typedef struct File {
	int data_size;
	int file_size;
	unsigned char file_name[256];
	unsigned char data[50000];
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
	
	f[0].data_size = fread(f[0].data, sizeof(unsigned char), 50000, f1);
	f[1].data_size = fread(f[1].data, sizeof(unsigned char), 50000, f2);
	f[2].data_size = fread(f[2].data, sizeof(unsigned char), 50000, f3);
	
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
	FILE *ff, *f1, *f2, *f3;
	file f[3];
	int i;
	
	for(i = 0; i < 3; i++) {
		memset(f[i].file_name, '\0', 256);
		memset(f[i].data, '\0', 50000);
	}
	
	if((ff = fopen(argv[2], "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	for(i = 0; i < 3; i++) {
		fread(&(f[i].data_size), sizeof(int), 1, ff);
		fread(&(f[i].file_size), sizeof(int), 1, ff);
		fread(f[i].file_name, sizeof(unsigned char), f[i].file_size, ff);
		fread(f[i].data, sizeof(unsigned char), f[i].data_size, ff);
	}
	
	for(i = 0; i < 3; i++) {
		if((f1 = fopen(f[i].file_name, "wb")) == NULL) {
			printf("ファイルのオープンに失敗しました");
			exit(1);
		}
		fwrite(f[i].data, sizeof(unsigned char), f[i].data_size, f1);
		fclose(f1);
	}
	fclose(ff);
}