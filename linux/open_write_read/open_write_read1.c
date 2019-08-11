#include<stdio.h>
#include<sys/types.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int fd;
	char buf[20];
	fd = open("bhaskar.txt", O_CREAT | O_WRONLY | O_RDONLY, 0666);
	if(fd < 0)
	{
		perror("open:");
		exit(1);
	}
	if((write(fd, "bhaskar is good", sizeof("bhaskar is good"))) < 0)
	{
		perror("write:");
		exit(1);
	}
	close(fd);
	fd = open("bhaskar.txt", O_RDONLY);
	if((read(fd, buf, sizeof("bhaskar is good"))) < 0)
	{
		perror("read");
		exit(1);
	}
	buf[19] = '\0';
	printf("buf is:%s\n", buf);
	return 0;
}

	
