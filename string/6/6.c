#include <stdio.h>
	
void main(void)
{
	char s[80];
	int i, length;
	
	gets(s);
	length = strlen(s);
	
	for(i = 0; s[i]; i++) {
		if(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f')) {
			continue;
		} else {
			printf("%s ‚Í 16 i”‚Å‚Í‚ ‚è‚Ü‚¹‚ñ", s);
			break;
		}
	}
	
	if(i == length) {
		for(i = 0; s[i]; i++) {
			printf("%d", s[i]);
		}
	}
	//printf("%d",'a'); //97
	//printf("%d",'f'); //102
	//printf("%d", '0'); //48
	//printf("%d", '1'); //49
	//printf("%d", '9'); //57
}