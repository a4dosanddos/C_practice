#include <stdio.h>


void main(void)
{
	FILE *f;
	int i, j, size;
	int data_size;
	int file_size;
	unsigned char file_name[8];
	unsigned char data[11];
	
	memset(file_name, '\0', 8);
	memset(data, '\0', 11);
	
	if((f = fopen("test5.dat", "rb")) == NULL) {
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂���");
		exit(1);
	}
	
	fread(&data_size, sizeof(int), 1, f);
	fread(&file_size, sizeof(int), 1, f);
	fread(file_name, sizeof(unsigned char), file_size, f);
	fread(data, sizeof(unsigned char), data_size, f);
	
	printf("�f�[�^�̒���    : %d\n", data_size);
	printf("�t�@�C�����̒��� : %d\n", file_size);
	printf("�t�@�C����      : %s\n", file_name);
	printf("�f�[�^         : %s\n", data);
}
