#include <stdio.h>
#include <stdarg.h>

void test(int ct, ...);

void main(void)
{
	test(2, 10, 20);
	test(5, 10, 20, 30, 40, 50);
}

void test(int ct, ...)
{
	int i, wk, ans = 0;
	va_list ap;
	
	// ÅIˆø”‚ğw’è‚µ‚Ä ap ‚ğİ’è
	va_start(ap, ct);
	
	for(i = 1; i <= ct; i++) {
		wk = va_arg(ap, int);
		printf("%d ", wk);
	}
	printf("\n");
	
	va_end(ap);
}