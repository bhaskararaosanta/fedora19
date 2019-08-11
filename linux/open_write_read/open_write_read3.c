#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	char wmsg[20] = "Hello bhaskar";
	char rmsg[20];

	int fd, retw, retr;
	if((fd = open("bhaskar", O_CREAT | O_WRONLY, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	//if((retw = write(fd, wmsg, sizeof("Hello bhaskar"))) < 0)
	if((retw = write(fd, wmsg, sizeof(wmsg))) < 0)
	{
		printf("return value of write system call:%d\n", retw);
		perror("write");
		exit(EXIT_FAILURE);
	}
	close(fd);
	
	if((fd = open("bhaskar", O_RDONLY, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	//if((retr = read(fd, rmsg, sizeof("Hello bhaskar"))) < 0)
	if((retr = read(fd, rmsg, sizeof(wmsg))) < 0)
	{
		printf("return value of read system call:%d\n", retr);
		perror("read");
		exit(EXIT_FAILURE);
	}

	close(fd);

	printf("Read message is:%s\n", rmsg);
	
	return 0;
}

