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
		if(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'f')) {
			continue;
		} else {
			printf("%s ‚Í 16 i”‚Å‚Í‚ ‚è‚Ü‚¹‚ñ", s);
			break;
		}
	}
	
	if(i == length) {
		for(i = 0; s[i]; i++) {
			if(s[i] == 'f') {
				result += 15 * pow(16.0, (length-i-1));
			} else if(s[i] == 'e') {
				result += 14 * pow(16.0, (length-i-1));
			} else if(s[i] == 'd') {
				result += 13 * pow(16.0, (length-i-1));
			} else if(s[i] == 'c') {
				result += 12 * pow(16.0, (length-i-1));
			} else if(s[i] == 'b') {
				result += 11 * pow(16.0, (length-i-1));
			} else if(s[i] == 'a') {
				result += 10 * pow(16.0, (length-i-1));
			} else if(s[i] == '9') {
				result += 9 * pow(16.0, (length-i-1));
			} else if(s[i] == '8') {
				result += 8 * pow(16.0, (length-i-1));
			} else if(s[i] == '7') {
				result += 7 * pow(16.0, (length-i-1));
			} else if(s[i] == '6') {
				result += 6 * pow(16.0, (length-i-1));
			} else if(s[i] == '5') {
				result += 5 * pow(16.0, (length-i-1));
			} else if(s[i] == '4') {
				result += 4 * pow(16.0, (length-i-1));
			} else if(s[i] == '3') {
				result += 3 * pow(16.0, (length-i-1));
			} else if(s[i] == '2') {
				result += 2 * pow(16.0, (length-i-1));
			} else if(s[i] == '1') {
				result += 1 * pow(16.0, (length-i-1));
			} else if(s[i] == '0') {
				result += 0 * pow(16.0, (length-i-1));
			}
		}
	}
	if(result != 0) {
		printf("%f", result);
	}
	//printf("%d",'a'); //97
	//printf("%d",'f'); //102
	//printf("%d", '0'); //48
	//printf("%d", '1'); //49
	//printf("%d", '9'); //57
}