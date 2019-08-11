#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char buf[50], writebuf[30] = "Hello, how are you";
	int fd, retwrite, retread, retclose, retlseek;
	printf("buffer length is:%d\n", strlen(writebuf));

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_WRONLY, 00666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("file decriptor value is:%d\n", fd);

	/* ssize_t write(int fd, const char *buf, size_t count); */
	if((retwrite = write(fd, writebuf, (strlen(writebuf)))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write:%d\n", retwrite);

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close:%d\n", retclose);


	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDONLY, 00666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	printf("file decriptor value is:%d\n", fd);

	/* loff_t lseek(int fd, off_t offset, int whence); */
	if((retlseek = lseek(fd, 0, SEEK_SET)) < 0)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("return value of lseek:%d\n", retlseek);
	
	/* ssize_t read(int fd, char *buf, size_t count); */
	if((retread = read(fd, buf, (strlen(writebuf)))) < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read:%d\n", retread);

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close:%d\n", retclose);
	printf("data read throgh read system call:%s\n", buf);

	return 0;
}
