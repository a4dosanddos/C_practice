#include <stdio.h>

int (*calc)(int a, int b);
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

void main(void)
{
	int a = 10;
	int b = 5;
	
	calc = add;
	printf("add : %d\n", calc(a, b));
	calc = sub;
	printf("sub : %d\n", calc(a, b));
	calc = mul;
	printf("mul : %d\n", calc(a, b));
	calc = div;
	printf("div : %d\n", calc(a, b));
}

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int div(int a, int b)
{
	return a / b;
}