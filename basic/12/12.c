#include <stdio.h>
#include <stdlib.h>
	
struct OneWayList {
	char data[50];
	int num;
	struct OneWayList *next;
};

void main(void)
{
	int i, n;
	char c[10];
	struct OneWayList *owl;
	
	gets(c);
	n = atoi(c);
	
	owl = (struct OneWayList *)calloc(n, sizeof(struct OneWayList));
	//printf("%d\n", _msize(owl));
	
	for(i = 0; i < n; i++) {
		strcpy(owl[i].data, "abcde");
		owl[i].num = i;
		owl[i].next = &owl[i+1];
	}
	
	for(i = 0; owl[i].next != NULL; i++) {
		printf("%s ", owl[i].data);
		printf("%d\n", owl[i].num);
	}
}