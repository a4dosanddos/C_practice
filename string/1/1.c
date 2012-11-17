#include <stdio.h>

int cmp(const char *a, const char *b);

void main(void)
{
	char s1[4] = "gth";
	char s2[4] = "adf";
	char s3[4] = "cfr";
	char *p[3] = {s1, s2, s3};
	char *min, *wk;
	int i, j, k;
	int l = 0;
	
	for(i = 0; i < 3; i++) {
		min = p[i];
		for(j = i; j < 3; j++) {
			if(cmp(min, p[j]) > 0) {
				min = p[j];
				k = j;
				l++;
			}
		}
		if(l >= 1) {
			wk = p[i];
			p[i] = min;
			p[k] = wk;
			l = 0;
		}
	}
	for(i = 0; i < 3; i++) {
		printf("%s\n", p[i]);
	}
}

int cmp(const char *a, const char *b)
{
	int n;
	//printf("%s %s\n", a, b);
	for(n = 0; n < 3; n++) {
		if(*a == *b) {
			a++;
			b++;
			continue;
		} else if(*a > *b) {
			return 1;
		} else {
			return -1;
		}
	}
	return 0;
}