#include <stdio.h>

struct x86_sub {
	unsigned char AL;
	unsigned char AH;
};

union x86 {
	unsigned int EAX;
	unsigned short AX;
	struct x86_sub sub;
};

void main(void)
{
	union x86 a;
	a.EAX = 0x12345678;
	printf("EAX : %x\n", a.EAX);
	printf("AX : %x\n", a.AX);
	printf("AL : %x\n", a.sub.AL);
	printf("AH : %x\n", a.sub.AH);
	
	a.sub.AL = 0x99;
	printf("EAX : %x\n", a.EAX);
	printf("AX : %x\n", a.AX);
	printf("AL : %x\n", a.sub.AL);
	printf("AH : %x\n", a.sub.AH);
}