#include <stdio.h>
	
void main(void)
{
	char in1[80], in2[80];
	int i1, length1, length2;
	int i2 = 0;
	int cnt = 0;
	
	printf("•¶Žš—ñ“ü—Í1 : ");gets(in1);
	printf("•¶Žš—ñ“ü—Í2 : ");gets(in2);
	length1 = strlen(in1);
	length2 = strlen(in2);
	
	for(i1 = 0; i1 < length1; i1++) {
		if(in1[i1] == in2[i2]) {
			for(i2 = 1; i2 < length2; i2++) {
				if(in1[i1+i2] != in2[i2]) {
					break;
				}
			}
			if(length2 == i2) {
				cnt++;
			}
		}
		i2 = 0;
	}
	printf("“ü—Í•¶Žš—ñ %s ‚É %s ‚ÍA%d ‰ñoŒ»‚µ‚Ü‚·\n", in1, in2, cnt);
}