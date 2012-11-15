#include <stdio.h>
	
void main(void)
{
	unsigned int n;
	
	n = 0x53445352;
	while(putchar(n & 0xFF))
		n >>= 8;
}
