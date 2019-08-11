#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int fd;
	char buf[20];

	fd = open("Bhaskar.txt", O_CREAT | O_APPEND | O_WRONLY, 0666);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	write(fd, "Hello World!\n", 13);
	close(fd);

	fd = open("Bhaskar.txt", O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(1);
	}
	read(fd, buf, 13);
	buf[12] = '\0';
	printf("Buffer read is:%s\n", buf);

	return 0;
}

