#include <stdio.h>

void count(void);

void main(void)
{
	int i;
	for(i=0; i<10;i++) {
		count();
	}
}

void count(void)
{
	static int i = 0;
	i++;
	printf("���̊֐��̌Ăяo���񐔂́A%d ��ڂł��B\n",i);
}