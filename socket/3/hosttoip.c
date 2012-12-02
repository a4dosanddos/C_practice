#include <winsock2.h>
#include <stdio.h>
#pragma comment(lib, "wsock32.lib")
	
void main(int argc, char *argv[])
{
	WSADATA wsaData;
	HOSTENT *host;
	int i;
	
	if(argc == 1) {
		printf("ƒzƒXƒg‚ðˆø”‚É—^‚¦‚Ä‚­‚¾‚³‚¢");
		exit(1);
	}
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	host = gethostbyname(argv[1]);
	
	for(i = 0; host->h_addr_list[i]; i++) {
		printf( "IP : %d.%d.%d.%d\n",
				(BYTE)host->h_addr_list[i][0],
				(BYTE)host->h_addr_list[i][1],
				(BYTE)host->h_addr_list[i][2],
				(BYTE)host->h_addr_list[i][3]);
	}
}