#include <stdio.h>
#include <winsock2.h>
#pragma once
#pragma comment(lib,"ws2_32.lib")

void main(void)
{
	WSADATA wsaData;
	SOCKET sock0, sock1;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len, n;
	char recvmsg[256];
	
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	
	sock0 = socket(AF_INET, SOCK_STREAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5200);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind(sock0, (struct sockaddr *)&addr, sizeof(addr));
	
	listen(sock0, 5);
	
	len = sizeof(client);
	sock1 = accept(sock0, (struct sockaddr *)&client, &len);
	
	memset(recvmsg, 0, sizeof(recvmsg));
	n = recv(sock1, recvmsg, sizeof(recvmsg), 0);
	printf("クライアントから通信を受け付けました : %s\n", recvmsg);
		
	closesocket(sock1);
	
	WSACleanup();
}