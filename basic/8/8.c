#include <stdio.h>
	
void main(int argc, char *argv[])
{
	int num[] = {15, 60, 50, 80, 1, 15, 70, 100, 35, 20};
	int i;
	int length;
	int in;
	
	in = atoi(argv[1]);
	length = sizeof num / sizeof num[0];
	
	for(i = 0; i < length; i++) {
		if (in == num[i]) {
			printf("あなたの入力した[%d]は、%d番目にあります\n", in, i+1);
			break;
		}
	}
	
	if (i == length) {
		printf("あなたの入力した[%d]は、配列内にありません\n", in);
	}
}