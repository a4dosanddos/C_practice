#include <stdio.h>

__declspec(dllimport) int Plus(int n1, int n2);

void main(void)
{
	int result = Plus(10, 20);
	printf("%d", result);
}