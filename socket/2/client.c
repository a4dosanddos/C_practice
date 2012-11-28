#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib") 
	
void main(void)
{
	WSADATA wsaData;
	struct sockaddr_in server;
	SOCKET sock;
	char buf[32], ipaddr[16], sendmsg[256];
	int n;
	
	printf("IPアドレス : ");gets(ipaddr);
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_port = htons(5100);
	server.sin_addr.S_un.S_addr = inet_addr(ipaddr);
	
	connect(sock, (struct sockaddr *)&server, sizeof(server));
	
	while(1) {
		memset(sendmsg, 0, sizeof(sendmsg));
		printf("サーバへ送信するメッセージ : ");gets(sendmsg);
		send(sock, sendmsg, sizeof(sendmsg), 0);
		
		memset(buf, 0, sizeof(buf));
		n = recv(sock, buf, sizeof(buf), 0);
		
		if(n == -1) {
			break;
		}
		
		printf("サーバから受信したメッセージ : %s\n", buf);
		printf("%d\n", n);
	}
	WSACleanup();
}