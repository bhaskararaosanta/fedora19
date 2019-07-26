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
	printf("Open ISM_TestDevice......\n");
	fd = open("ISM_TestDevice", O_RDWR, 0777);

	write(fd, "INDIAN SERVICE MACHINE", 23);
	lseek(fd, 7, SEEK_SET);
	read(fd, buffer, 8);
	buffer[8] = '\0';
	printf("Data read is:%s\n", buffer);
	lseek(fd, -2, SEEK_CUR);
	lseek(fd, -5, SEEK_END);

	printf("Close the device file......\n");
	close(fd);
	return 0;
}
