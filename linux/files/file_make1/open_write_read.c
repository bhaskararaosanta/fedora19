#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	struct stat statbuf;
	
	char buf[50], writebuf[30] = "hello emedded world";
	int fd, retwrite, retfstat, retread, retclose, retlseek;

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of open:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retwrite = write(fd, writebuf, sizeof("hello embedded world"))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	sleep(200);
	printf("return value of write:%d\n", retwrite);
	
	/* int fstat(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &statbuf)) < 0)
	{
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);

	/* off_t lseek(int fd, off_t offset, int whence); */
	if((retlseek = lseek(fd, 6, SEEK_SET)) < 0)
	{
		perror("lseek");
		exit(EXIT_FAILURE);
	}
	printf("return value of lseek:%d\n", retlseek);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retread = read(fd, buf, sizeof("hello embedded world"))) < 0)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read:%d\n", retread);
	
	printf("data read using read system call:%s\n", buf);

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close:%d\n", retclose);

	printf("********* printing file statistics ************\n");

	printf("ID of device containing file	:%d\n", statbuf.st_dev);
        printf("inode number 			:%d\n", statbuf.st_ino);
        printf("file type and mode		:%o\n", statbuf.st_mode);
        printf("number of hard links		:%d\n", statbuf.st_nlink);
        printf("user ID of owner		:%d\n", statbuf.st_uid);
        printf("group ID of owner		:%d\n", statbuf.st_gid);
        printf("device ID (if special file)	:%d\n", statbuf.st_rdev);
        printf("total size, in bytes		:%d\n", statbuf.st_size);
        printf("blocksize for filesystem I/O	:%d\n", statbuf.st_blksize);
        printf("number of 512B blocks allocated	:%d\n", statbuf.st_blocks);

	return 0;
}



