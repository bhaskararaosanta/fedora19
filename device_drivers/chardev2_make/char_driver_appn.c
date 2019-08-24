#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buf[100];
	int fd, retwrite, retread, retlseek, retclose;
	if((fd = open("TestDeviceFile", O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file descriptor: %d\n", fd);
	
	if((retwrite = write(fd, "Bhaskar is a good boy", sizeof("Bhaskar is a good boy"))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file write: %d\n", retwrite);

	if((retlseek = lseek(fd, 7, SEEK_SET)) < 0)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file lseek:%d\n", retlseek);

	if((retread = read(fd, buf, sizeof("Bhaskar is a good boy"))) < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file read: %d\n", retread);

	printf("Data read through kernel driver:%s\n", *buf);
	
	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file close: %d\n", retclose);

	return 0;
}
	
