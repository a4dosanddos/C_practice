#include <stdio.h>
#include <conio.h>
#include <winsock2.h>
#pragma once
#pragma comment(lib,"ws2_32.lib")
	
void main(void)
{
	WSADATA wsaData;
	SOCKET sock;
	struct sockaddr_in addr;
	char buf[2048];
	
	WSAStartup(MAKEWORD(2, 0), &wsaData);
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5000);
	addr.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind(sock, (struct sockaddr *)&addr, sizeof(addr));
	
	memset(buf, 0, sizeof(buf));
	recv(sock, buf, sizeof(buf), 0);
	
	printf("%s\n", buf);
	
	closesocket(sock);
	WSACleanup();
	getch();
}