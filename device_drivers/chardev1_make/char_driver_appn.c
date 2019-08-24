#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char buf[100];
	int fd, retwrite, retread, retclose;
	if((fd = open("TestDeviceFile", O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file descriptor: %d\n", fd);
	
	if((retwrite = write(fd, "Hello Bhaskar", sizeof("Hello Bhaskar"))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file write: %d\n", retwrite);

	if((retread = read(fd, buf, sizeof("Hello Bhaskar"))) < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file read: %d\n", retread);
	
	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of special device file close: %d\n", retclose);

	return 0;
}
	
