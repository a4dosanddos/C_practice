#include <stdio.h>
#define PERIOD 46

void main(int argc, char *argv[])
{
	char *p;
	int i, length;
	
	if(argv[1] == NULL) {
		printf("�p�X����͂��Ă�������");
		exit(1);
	}
	
	p = argv[1];
	length = strlen(p);

	for(i = length - 1; i >= 0; i--) {
		//printf("%c", p[i]);
		if(p[i] == PERIOD) {
			printf("���͂��ꂽ�p�X�̊g���q�� %s �ł�\n", &p[i]);
			p[i] = '\0';
			printf("���͂��ꂽ�p�X�� %s �ł�\n", p);
			break;
		}
	}

	if(i == -1) {
		printf("�g���q������܂���");
	}
}