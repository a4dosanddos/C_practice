#include <winsock2.h>
#include <stdio.h>
#include <string.h>
#pragma comment(lib, "wsock32.lib")
	
void main(void)
{
	WSADATA wsaData;
	SOCKET sock1, sock2;
	struct sockaddr_in server;
	struct sockaddr_in client;
	int n;
	char recvbuf[500], sendbuf[500];
	char *html;
	FILE *file;
	char s[256];
	
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
	
	n = sizeof(client);
	sock2 = accept(sock1, (struct sockaddr *)&client, &n);
	
	memset(recvbuf, 0, sizeof(recvbuf));
	n = recv(sock2, recvbuf, sizeof(recvbuf), 0);
	strtok(recvbuf, " ");
	html = strtok(NULL, " ");
	printf("%s\n", html);
	
	memset(sendbuf, 0, sizeof(sendbuf));
	if((file = fopen(++html, "r")) == NULL) {
		strcpy(sendbuf, "HTTP/1.1 404 Not Found\r\n");
		send(sock2, sendbuf, strlen(sendbuf), 0);
		//printf("404\n");
		exit(1);
	} else {
		strcpy(sendbuf, "HTTP/1.1 200 OK\r\n");
		strcat(sendbuf, "\r\n");
		while((fgets(s, 256, file)) != NULL) {
			strcat(sendbuf, s);
		}
		printf("%s\n", sendbuf);
		send(sock2, sendbuf, strlen(sendbuf), 0);
		//printf("200\n");
	}
	fclose(file);
	closesocket(sock2);
	closesocket(sock1);
	WSACleanup();
}