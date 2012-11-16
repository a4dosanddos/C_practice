#include <stdio.h>

void bblsort(int num[]);
int check(int num[]);

int length;
	
void main(void)
{
	int num[] = {5, 60, 50, 80, 1, 15, 70, 100, 35, 20};
	//int num[] = {5, 60, 50, 80, 15, 15, 70, 100, 35, 20};
	//int num[] = {1, 2, 3, 4, 5};
	int i;
	
	length = sizeof num / sizeof num[0];
	
	while(!check(num)) {
		bblsort(num);
	}
	
	for(i = 0; i < length; i++) {
		printf("%d ",num[i]);
	}
}

void bblsort(int num[]) {
	int i;
	int wk;
	
	for(i = 0; i < length - 1; i++) {
		if(num[i] > num[i+1]) {
			wk = num[i+1];
			num[i+1] = num[i];
			num[i] = wk;
		}
	}
}

int check(int num[]) {
	int flg = 1;
	int i;
	
	for(i = 0; i < length - 1; i++) {
		if(num[i] > num[i+1]) {
			flg = 0;
			break;
		}
	}
	return flg;
}