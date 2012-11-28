#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
	
void main(void)
{
	WSADATA wsaData;
	SOCKET sock, sock0;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;
	char recvmsg[256];
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	sock0 = socket(AF_INET, SOCK_STREAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5100);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));
	
	listen(sock0, 5);
	
	while(1) {
		len = sizeof(client);
		sock = accept(sock0, (struct sockaddr *)&client, &len);
	
		memset(recvmsg, 0, sizeof(recvmsg));
		recv(sock, recvmsg, sizeof(recvmsg), 0);
		//printf("%s\n", recvmsg);
		send(sock, recvmsg, sizeof(recvmsg), 0);
		
		closesocket(sock);
	}
	WSACleanup();
}