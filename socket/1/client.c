#include <stdio.h>
#include <winsock2.h>
#pragma once
#pragma comment(lib,"ws2_32.lib")
	
void main(void)
{
	char ip[80], port[80], msg[256];
	WSADATA wsaData;
	SOCKET sock;
	struct sockaddr_in addr;
	
	printf("IPアドレスを入力してください : ");gets(ip);
	printf("PORT番号を入力してください : ");gets(port);
	
	// winsock の初期化
	WSAStartup(MAKEWORD(2,0), &wsaData);
	sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(port));
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	
	sendto(sock, "HELLO", 5, 0, (struct sockaddr *)&addr, sizeof(addr));
	
	closesocket(sock);
	// winsock の終了
	WSACleanup();
}