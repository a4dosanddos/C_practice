#include <stdio.h>
#include <windows.h>

#define BUFLEN 80

void main(void)
{
	DWORD dw = 0x53445352;
	DWORD dwtemp = 0;
	TCHAR tc[BUFLEN];
	int i;
	dwtemp = dw;
	for(i = 0; i < BUFLEN - 1 && dwtemp != 0x0; i++){
    	tc[i] = dwtemp & 0xFF;
    	dwtemp >>= 8;
	}
	tc[i] = '\0';
	//printf(TEXT("ORGINAL DATA : %x\n"), dw);
	//printf(TEXT("CHAR DATA    : %s\n"), tc);
	printf("ORGINAL DATA : %x\n", dw);
	printf("CHAR DATA    : %s\n", tc);
}