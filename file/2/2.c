#include <stdio.h>
#include <stdlib.h>
	
void main(void)
{
	FILE *f;
	char s[80];
	
	printf("���������͂��Ă������� : ");gets(s);
	
	if((f = fopen("test.txt", "w")) == NULL) {
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂���");
		exit(1);
	}
	
	fputs(s, f);
	printf("�t�@�C���ւ̏o�͂��������܂���");
	
	fclose(f);
}