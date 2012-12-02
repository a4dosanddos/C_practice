#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
	
void main(int argc, char *argv[])
{
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	char buf[256];
	int n;
	
	HOSTENT *host;
	int **addrptr;
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	host = gethostbyname(argv[1]);
	addrptr = (int **)host->h_addr_list;
	
	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	server.sin_addr.S_un.S_addr = *(*addrptr);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	connect(sock, (struct sockaddr *)&server, sizeof(server));
		
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "GET / HTTP/1.1\r\n\r\n");
	
	n = send(sock, buf, (int)strlen(buf), 0);
	if(n < 0) {
		printf("send : %d\n", WSAGetLastError());
		exit(1);
	}
	
	while(n > 0) {
		memset(buf ,0 ,sizeof(buf));
		n = recv(sock, buf, sizeof(buf), 0);
		if(n < 0) {
			printf("recv : %d\n", WSAGetLastError());
			exit(1);
		}
		printf("%s", buf);
	}
	
	closesocket(sock);
	WSACleanup();
}