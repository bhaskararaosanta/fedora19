#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int fd;
char buffer[20];

int main()
{
	printf("Open TestDevfile\n");
	fd = open("TestDeviceFile", O_RDWR, 0666);

	printf("write from user space to driver\n");
	write(fd, "Bhaskar", 7);

//	printf("using lseek\n");
//	lseek(fd, SEEK_SET, 0);

	printf("read from driver to user space\n");
	read(fd, buffer, 5);
	printf("data read from driver is:%s\n", buffer);

	printf("close the driver\n");
	close(fd);

	return 0;
}

