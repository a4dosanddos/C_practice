#include <stdio.h>
#include <math.h>

void main(void)
{
	char s[80];
	int i, length;
	double result = 0;
	
	gets(s);
	length = strlen(s);
	
	for(i = 0; s[i]; i++) {
		if('A' <= s[i] && s[i] <= 'F') {
			s[i] = s[i] + 32;
		}
	}
	
	for(i = 0; s[i]; i++) {
		// s[i] = tolower(s[i]);
		if(('0' > s[i] || s[i] > '9') && ('a' > s[i] || s[i] > 'f')) {
			printf("%s ÇÕ 16 êiêîÇ≈ÇÕÇ†ÇËÇ‹ÇπÇÒ", s);
			exit(1);
		}
	}
	
	for(i = 0; s[i]; i++) {
		if(s[i] <= 'a') {
			result += (s[i] - '0') * pow(16.0, (length-i-1));
		} else {
			result += (s[i] - 'a' + 10) * pow(16.0, (length-i-1));
		} 
	}
	
	printf("%f", result);
	
	//printf("%d",'a'); //97
	//printf("%d",'f'); //102
	//printf("%d", '0'); //48
	//printf("%d", '1'); //49
	//printf("%d", '9'); //57
	//printf("%d", 'A'); //65
}