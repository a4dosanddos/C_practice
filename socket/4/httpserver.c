#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#pragma comment(lib, "wsock32.lib")

void recvfunc(SOCKET sock)
{
	char recvbuf[500], sendbuf[500];
	char s[256];
	char *html;
	FILE *file;
	int n;
	
	printf("---*---*---*---*---*---*---*---\n");
	
	memset(recvbuf, 0, sizeof(recvbuf));
	n = recv(sock, recvbuf, sizeof(recvbuf), 0);
	//printf("%s\n", recvbuf);
	strtok(recvbuf, " ");
	html = strtok(NULL, " ");
	printf("%s\n", html);
	
	memset(sendbuf, 0, sizeof(sendbuf));
	if((file = fopen(++html, "r")) == NULL) {
		strcpy(sendbuf, "HTTP/1.1 404 Not Found\r\n");
		printf("%s\n", sendbuf);
		send(sock, sendbuf, strlen(sendbuf), 0);
		//printf("404\n");
	} else {
		strcpy(sendbuf, "HTTP/1.1 200 OK\r\n");
		strcat(sendbuf, "\r\n");
		while((fgets(s, 256, file)) != NULL) {
			strcat(sendbuf, s);
		}
		printf("%s\n", sendbuf);
		send(sock, sendbuf, strlen(sendbuf), 0);
		//printf("200\n");
		fclose(file);
	}
	closesocket(sock);
	
	printf("---*---*---*---*---*---*---*---\n");
}

void main(void)
{
	WSADATA wsaData;
	SOCKET sock1, sock2;
	struct sockaddr_in server;
	struct sockaddr_in client;
	int n;
	HANDLE h;
	
	WSAStartup(MAKEWORD(2,0), &wsaData);
	
	// ソケットの作成
	sock1 = socket(AF_INET, SOCK_STREAM, 0);
	
	server.sin_family = AF_INET;
	server.sin_port = htons(80);
	server.sin_addr.S_un.S_addr = INADDR_ANY;
	
	// バインドする
	bind(sock1, (struct sockaddr *)&server, sizeof(server));
	
	// リッスン
	listen(sock1, 5);
	
	while(1) {
		n = sizeof(client);
		sock2 = accept(sock1, (struct sockaddr *)&client, &n);
		h = (HANDLE)_beginthread(recvfunc, 0, sock2);	
	}
	closesocket(sock1);
	WSACleanup();
}