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
	
	printf("�X���b�h���J�n���܂�\n");
	while(1) {
		memset(recvmsg, 0, sizeof(recvmsg));
		ret = recv(sock, recvmsg, sizeof(recvmsg), 0);
		if(ret == SOCKET_ERROR || ret == 0) {
			break;
		}
		printf("�N���C�A���g���瑗�M���ꂽ�̂� %s �ł��B\n", recvmsg);
		
		send(sock, recvmsg, strlen(recvmsg), 0);
	}
	printf("�X���b�h���I�����܂�\n");
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
		printf("�N���C�A���g����̐ڑ����󂯕t���܂���\n");
		h = (HANDLE)_beginthread(recvfunc, 0, sock);
	}
	WSACleanup();
}