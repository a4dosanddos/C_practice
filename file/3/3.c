#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
void main(void)
{
	FILE *f;
	char wk[256];
	char *p;
	char ipaddr[256];
	int port;
	
	if((f = fopen("test.txt", "r")) == NULL) {
		printf("�t�@�C���̃I�[�v���Ɏ��s���܂���");
		exit(1);
	}
	
	while((fgets(wk, 256, f)) != NULL) {
		p = strtok(wk, ":");
		strcpy(ipaddr, p);
		p = strtok(NULL, ":");
		port = atoi(p);
		printf("%s:%d\n", ipaddr, port);
	}
}