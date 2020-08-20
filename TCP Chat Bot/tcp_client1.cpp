#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#define DEFAULT_PORT 12000
int main()
{
	int connfd = 0;
	int cLen = 0;
	struct sockaddr_in client;
	/*if(argc<2)
	{
		printf("Uasge: clientent[server IP address]\n");
		return -1;
	}*/
	client.sin_family = AF_INET;
	client.sin_port = htons(DEFAULT_PORT);
	client.sin_addr.s_addr = inet_addr("127.0.0.1");
	connfd = socket(AF_INET, SOCK_STREAM, 0);
	if(connfd<0)
	{
		perror("socket");
		return -1;
	}
	if(connect(connfd, (struct sockaddr*)&client, sizeof(client))<0)
	{
		perror("connect");
		return -1;
	}
	char buffer[1024];
	bzero(buffer, sizeof(buffer));
	recv(connfd, buffer, 1024, 0);
	printf("recv: %s\n", buffer);
	bzero(buffer, sizeof(buffer));
	strcpy(buffer, "this is Alice!\n");
	send(connfd, buffer, 1024, 0);
	while(1)
	{
		bzero(buffer, sizeof(buffer));
		scanf("%s", buffer);
		int p = strlen(buffer);
		buffer[p] = '\0';
		send(connfd, buffer, 1024, 0);
		//printf("i have send buffer");
	}
	close(connfd);
	return 0;
}
