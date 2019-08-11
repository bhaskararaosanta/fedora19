#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdlib.h>

int main()
{
	int fd;
	char buf[20], *text = "Hello bhaskar";
	fd = open("bhaskar2.txt", O_CREAT | O_WRONLY, 0666);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	printf("value of fd is:%d\n", fd);
	//if((write(fd, "Hello bhaskar", sizeof("hello bhaskar"))) < 0)
	if((write(fd, text, sizeof("hello bhaskar"))) < 0)
	{
		perror("write");
		exit(1);
	}
	close(fd);
	perror("close");

	fd = open("bhaskar2.txt", O_CREAT | O_RDONLY, 0666);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	printf("value of fd is:%d\n", fd);
	//if((read(fd, buf, sizeof("hello bhaskar"))) < 0)
	if((read(fd, buf, sizeof("hello bhaskar"))) < 0)
	{
		perror("read");
		exit(1);
	}
	close(fd);
	perror("close");

	printf("Data read is:%s\n", buf);

	return 0;
}



