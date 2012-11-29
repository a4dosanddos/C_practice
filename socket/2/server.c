#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <sys/types.h>
#include <windows.h>
#pragma comment(lib, "wsock32.lib") 

void recvfunc(SOCKET sock)
{
	char recvmsg[256];
	int ret;
	
	printf("スレッドを開始します\n");
	while(1) {
		memset(recvmsg, 0, sizeof(recvmsg));
		ret = recv(sock, recvmsg, sizeof(recvmsg), 0);
		if(ret == SOCKET_ERROR || ret == 0) {
			break;
		}
		printf("クライアントから送信されたのは %s です。\n", recvmsg);
		
		send(sock, recvmsg, strlen(recvmsg), 0);
	}
	printf("スレッドを終了します\n");
	closesocket(sock);
}

void main(void)
{
	WSADATA wsaData;
	SOCKET sock0, sock;
	struct sockaddr_in addr;
	struct sockaddr_in client;
	int len;
	
	HANDLE h;
	
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
		printf("クライアントからの接続を受け付けました\n");
		h = (HANDLE)_beginthread(recvfunc, 0, sock);
	}
	WSACleanup();
}