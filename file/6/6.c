#include <stdio.h>

typedef struct USER {
	int id;
	char name[8];
	int num;
} user;

void main(void)
{
	FILE *f;
	user u[10];
	unsigned char buf[500];
	int i, j, k, l, size;
	
	if((f = fopen("test6.dat", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	size = fread(buf, sizeof(unsigned char), 500, f);
	
	printf("バイナリファイルの内容\n-----");
	for(i = 0; i < size; i++) {
		if(i % 16 == 0) printf("\n");
		printf("%x", buf[i]);
	}
	printf("\n");
	printf("-----\n");
	
	// 構造体の初期化
	for(i = 0; i < 10; i++) {
		u[i].id = 0;
		u[i].num = 0;
	}
	
	for(i = 0, j = 0, k = 0, l = 0; i < size; i++) {
		if (i % 16 < 4) {
			u[k].id += buf[i];
		} else if ((4 <= i % 16) && (i % 16 < 12)) {
			u[k].name[j] = buf[i];
			j++;
			if (j == 8) {
				j = 0;
			}
		} else {
			u[k].num += buf[i];
		}
		if (i % 16 == 15) {
			k++;
		}
	}
	
	printf("id   : %d\n", u[8].id);
	printf("name : %s\n", u[8].name);
	printf("num  : %d\n", u[8].num);
	printf("id   : %d\n", u[5].id);
	printf("name : %s\n", u[5].name);
	printf("num  : %d\n", u[5].num);
	printf("id   : %d\n", u[7].id);
	printf("name : %s\n", u[7].name);
	printf("num  : %d\n", u[7].num);
	printf("id   : %d\n", u[3].id);
	printf("name : %s\n", u[3].name);
	printf("num  : %d\n", u[3].num);
	printf("id   : %d\n", u[1].id);
	printf("name : %s\n", u[1].name);
	printf("num  : %d\n", u[1].num);
}