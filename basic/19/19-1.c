#include <stdio.h>
	
__declspec(dllexport) int Plus(int n1, int n2)
{
	return n1 + n2;
}