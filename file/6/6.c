#include <stdio.h>

typedef struct USER {
	int id;
	char name[6];
	int num;
} user;

void main(void)
{
	FILE *f;
	user u;
	unsigned char buf[500];
	int i, j, k, l, size;
	
	if((f = fopen("test6.dat", "rb")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	fseek(f, 112, SEEK_SET);
	fread(&u, 16, 1, f);
	printf("id   : %d\n", u.id);
	printf("name : %s\n", u.name);
	printf("num  : %d\n", u.num);
	
	fseek(f, 64, SEEK_SET);
	fread(&u, 16, 1, f);
	printf("id   : %d\n", u.id);
	printf("name : %s\n", u.name);
	printf("num  : %d\n", u.num);
	
	fseek(f, 96, SEEK_SET);
	fread(&u, 16, 1, f);
	printf("id   : %d\n", u.id);
	printf("name : %s\n", u.name);
	printf("num  : %d\n", u.num);
	
	fseek(f, 32, SEEK_SET);
	fread(&u, 16, 1, f);
	printf("id   : %d\n", u.id);
	printf("name : %s\n", u.name);
	printf("num  : %d\n", u.num);
	
	fseek(f, 0, SEEK_SET);
	//fseek(f, -48, SEEK_CUR);
	fread(&u, 16, 1, f);
	printf("id   : %d\n", u.id);
	printf("name : %s\n", u.name);
	printf("num  : %d\n", u.num);
}