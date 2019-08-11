#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[20], b[20] = "bhaskar is good";
	int stringlength = strlen(b);
	printf("string length of array b is:%d\n", strlen(b));
	int fd, retwrite, retread, retopen, retclose;
	
	/* open: int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("./bhaskar.txt", O_CREAT | O_WRONLY, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("value of O_CREAT, O_WRONLY, O_RDONLY and O_RDWR:%d   %d   %d   %d\n", O_CREAT, O_WRONLY, O_RDONLY, O_RDWR);
	printf("value of file descriptor:%d\n", fd);

	/* write: ssize_t write(int fd, const void *buf, size_t count); */
	//if((retwrite = write(fd, "Hello world", sizeof("hello world"))) < 0)
	if((retwrite = write(fd, b, (stringlength))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write syscall:%d\n", retwrite);

	/* close: int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retclose);

	printf("\n\n\n");

	if((fd = open("./bhaskar.txt", O_RDONLY, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("value of file descriptor:%d\n", fd);

	/* read: ssize_t read(int fd, void *buf, size_t count); */
	//if((retread = read(fd, a, sizeof("hello world"))) < 0)
	if((retread = read(fd, a, (stringlength))) < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read syscall:%d\n", retread);

	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retclose);

	a[15] = '\0';

	printf("data read is:%s\n", a);

	return 0;
}


