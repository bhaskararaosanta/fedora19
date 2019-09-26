#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	int sockfd;
	struct sockaddr_in server;

	/* int socket(int domain, int type, int protocol); */
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("Return value of socket:%d\n", sockfd);

	server.sin_addr.s_addr = inet_addr("172.217.166.174"); // Google IP
	server.sin_family = AF_INET;
	server.sin_port = htons(80);

	if(connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		exit(EXIT_FAILURE);
	}

	puts("connected"); /* if above statements inside if not exectes means connected */

	return 0;
}

