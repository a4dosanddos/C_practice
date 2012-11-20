#include <stdio.h>
#include <math.h>

void main(void)
{
	char s[80];
	int i, idx;
	unsigned long result = 0;
	
	gets(s);

	for(i = 0; s[i]; i++){
		s[i] = tolower(s[i]);
		if(('0' > s[i] || s[i] > '9') && ('a' > s[i] || s[i] > 'f')){
			printf("16 i”‚Å‚Í‚ ‚è‚Ü‚¹‚ñ\n");
			return;
		}
	}
	
	for(i = i - 1, idx = 0; i >= 0; i--, idx++){
		if(s[i] >= 'a'){
			result += (unsigned long)((s[i] - 'a' + 10) * pow(16.0, idx));
		}
		else{
			result += (unsigned long)((s[i] - '0') * pow(16.0, idx));
		}
	}
	printf("%ld", result);
}