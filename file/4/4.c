#include <stdio.h>
#include <string.h>

struct Fruit {
	char name[80];
	int price;
};

void main(void)
{
	FILE *f;
	char s[80];
	char *p;
	int i = 0;
	struct Fruit fruit[7];
	
	if((f = fopen("fruit.txt", "r")) == NULL) {
		printf("ファイルのオープンに失敗しました");
		exit(1);
	}
	
	while((fgets(s, 80, f)) != NULL) {
		p = strtok(s, " ");
		strcpy(fruit[i].name, p);
		p = strtok(NULL, " ");
		fruit[i].price = atoi(p);
		i++;
	}
	
	qsort(fruit, 7, sizeof(fruit), func);
}

int func(const void *a, const void *b)
{
	if(((fruit *)a)->price > ((fruit *)b)->price) {
		
	} else if(((fruit *)a)->price < ((fruit *)b)->price) {
		
	}{ e
}