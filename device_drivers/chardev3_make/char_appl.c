#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
	char buf[20];
	int fd;
	fd = open("MyTestDevice", O_CREAT | O_RDWR, 0666);

	write(fd, "hello world", sizeof("hello world"));

	read(fd, buf, sizeof("hello world"));

	printf("data read from device is:%s\n", buf);

	close(fd);

	return 0;
}
