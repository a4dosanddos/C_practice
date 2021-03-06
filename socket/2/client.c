#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
	
void main(void)
{
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	char ipaddr[16], buf[256], sendmsg[256];
	int n;
	
	printf("IPアドレス : ");gets(ipaddr);
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	server.sin_family = AF_INET;
	server.sin_port = htons(5100);
	server.sin_addr.S_un.S_addr = inet_addr(ipaddr);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	connect(sock, (struct sockaddr *)&server, sizeof(server));
	
	while(1) {
		
		memset(sendmsg, 0, sizeof(sendmsg));
		printf("サーバへ送信するメッセージ : ");gets(sendmsg);
		send(sock, sendmsg, strlen(sendmsg), 0);
		
		memset(buf, 0, sizeof(buf));
		n = recv(sock, buf, sizeof(buf), 0);
		if(n == -1) {
			break;
		}
		printf("サーバから受信したメッセージ : %d %s\n", n, buf);
	}
	WSACleanup();
}