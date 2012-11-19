#include <stdio.h>
#define PERIOD 46

void main(int argc, char *argv[])
{
	char *p;
	int i, length;
	
	if(argc == 1) {
		printf("パスを入力してください");
		exit(1);
	}
	
	p = argv[1];
	length = strlen(p);

	for(i = length - 1; i >= 0; i--) {
		//printf("%c", p[i]);
		if(p[i] == PERIOD) {
			p[i] = '\0';
			printf("入力されたパスは %s です\n", p);
			printf("入力されたパスの拡張子は %s です\n", &p[i+1]);
			break;
		}
	}

	if(i == -1) {
		printf("拡張子がありません");
	}
}