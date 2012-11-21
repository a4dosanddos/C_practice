#include <stdio.h>
	
void main(void)
{
	char s[80];
	char *p;
	int i;
	int cnt = 1;
	
	gets(s);
	p = s;
	
	for(i = 0; s[i]; i++) {
		if(s[i] == ' ' || s[i] == ',' || s[i] == '#' || s[i] == ';' || s[i] == ':') {
			s[i] = '\0';
			printf("Token%d : %s\n", cnt, p);
			p = &s[i+1];
			cnt++;
		}
	}
	printf("Token%d : %s\n", cnt, p);
}