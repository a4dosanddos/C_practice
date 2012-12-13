#include <stdio.h>
#include <winsock2.h>
#pragma once
#pragma comment(lib,"ws2_32.lib")
	
void main(void)
{
	char ip[80], port[80], sendmsg[256], recvmsg[256];
	WSADATA wsaData;
	SOCKET sock;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	
	printf("IPアドレスを入力してください : ");gets(ip);
	printf("PORT番号を入力してください : ");gets(port);
	
	// winsock の初期化
	WSAStartup(MAKEWORD(2,0), &wsaData);
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(port));
	addr.sin_addr.S_un.S_addr = inet_addr(ip);
	
	client.sin_family = AF_INET;
	client.sin_port = htons(8000);
	client.sin_addr.S_un.S_addr = INADDR_ANY;
	
	bind(sock, (struct sockaddr *)&client, sizeof(client));
	connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	
	memset(sendmsg, 0, sizeof(sendmsg));
	printf("サーバへ送信するメッセージ : ");gets(sendmsg);
	send(sock, sendmsg, strlen(sendmsg), 0);
	printf("サーバへメッセージを送信しました。");
	
	closesocket(sock);
	// winsock の終了
	WSACleanup();
}