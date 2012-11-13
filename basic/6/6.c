#include <stdio.h>
	
int length;

void main(void)
{
	int num[] = {5, 60, 50, 80, 1, 15, 70, 100, 35, 20, 100, 5};
	//int num[] = {1, 2, 7, 4, 5, 3, 0, 10, 9};
	//int num[] = {0, 2, 7, 4, 5, 3, 1, 10, 9}; 1
	//int num[] = {0, 1, 7, 4, 5, 3, 2, 10, 9}; 2
	//int num[] = {0, 1, 2, 4, 5, 3, 7, 10, 9}; 3
	//int num[] = {0, 1, 2, 3, 5, 4, 7, 10, 9}; 4
	//int num[] = {0, 1, 2, 3, 4, 5, 7, 10, 9}; 5
	//int num[] = {0, 1, 2, 3, 4, 5, 7, 10, 9}; 6
	//int num[] = {0, 1, 2, 3, 4, 7, 7, 10, 9}; 7
	int i;
	int j;
	int k;
	int l = 0;
	int wk;
	int min;
	
	length = sizeof num / sizeof num[0];
	
	for(i = 0; i < length; i++) {
		min = num[i];
		for(j = i; j < length; j++) {
			if(num[j] < min) {
				min = num[j];
				k = j;
				l++;
			}
		}
		if(l >= 1) {
			wk = num[i];
			num[i] = min;
			num[k] = wk;
			l = 0;
		}
		//printf("%d, %d\n",i, num[i]);
	}
	
	for(i = 0; i < length; i++) {
		printf("%d ", num[i]);
	}
}