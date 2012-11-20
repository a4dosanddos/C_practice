#include <stdio.h>
	
void main(void)
{
	char s[80];
	int i;
	int cnt = 1;
	
	gets(s);
	
	printf("数値%d : %d\n", cnt, atoi(s));
	for(i = 0; s[i]; i++) {
		if(s[i] == ',') {
			cnt++;
			printf("数値%d : %d\n", cnt, atoi(s+i+1));
			// "12abc" をどうするか・・・
		}
	}
}