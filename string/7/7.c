#include <stdio.h>
	
void main(void)
{
	char s[80];
	int i;
	int cnt = 1;
	
	gets(s);
	
	printf("���l%d : %d\n", cnt, atoi(s));
	for(i = 0; s[i]; i++) {
		if(s[i] == ',') {
			cnt++;
			printf("���l%d : %d\n", cnt, atoi(s+i+1));
			// "12abc" ���ǂ����邩�E�E�E
		}
	}
}