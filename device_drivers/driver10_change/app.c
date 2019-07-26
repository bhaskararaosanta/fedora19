#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int fd;
char buffer[10];

int main()
{
	long int arg;
	printf("Open Testdevice file\n");
	fd = open("Testdevice", O_RDWR, 0777);

	write(fd, "Bhaskar is good", 15);
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, 8);
	buffer[8] = '\0';
	printf("Read data is:%s\n", buffer);
	lseek(fd, -2, SEEK_CUR);
	lseek(fd, -5, SEEK_END);

	printf("Close the device file\n");
	close(fd);
}
