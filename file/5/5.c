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
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂���");
		exit(1);
	}
	
	size = fread(buf, sizeof(unsigned char), 256, f);
	
	// �Ƃ肠�����\�����Ă݂�
	printf("�o�C�i���t�@�C���̓��e\n-----");
	for(i = 0; i < size; i++) {
		// ���₷���悤�ɉ��s������
		if(i % 16 == 0) printf("\n");
			printf("%X", buf[i]);
	}
	printf("\n");
	printf("-----\n");
	
	// �f�[�^�T�C�Y
	for(i = 0; i < 4; i++) {
		data_size += (int)buf[i];
	}
	// �t�@�C���T�C�Y
	for(i = 4; i < 8; i++) {
		file_size += (int)buf[i];
	}
	// �t�@�C����
	for(i = 8, j = 0; j < file_size; i++, j++) {
		file_name[j] = buf[i];
	}
	// �f�[�^
	for(i = 16, j = 0; j < data_size; i++, j++) {
		data[j] = buf[i];
	}
	printf("�f�[�^�̒���     : %d\n", data_size);
	printf("�t�@�C�����̒��� : %d\n", file_size);
	printf("�t�@�C����       : %s\n", file_name);
	printf("�f�[�^           : %s\n", data);
}
