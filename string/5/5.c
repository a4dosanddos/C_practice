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
			p[i+1] = 't';
			p[i+2] = 'e';
			p[i+3] = 's';
			p[i+4] = 's';
			p[i+5] = '\0';
			break;
		}
	}

	if(i == -1) {
		printf("�g���q������܂���");
	} else {
		printf("�ύX��̃t�@�C���p�X�� %s �ł�\n", p);
	}
}