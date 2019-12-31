#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	struct stat mystat;
	int i, fd, retw, retr, retl, retc, retfstat;
	char writebuf[30] = "Embedded is good", readbuf[30];

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_WRONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	i = printf("return value of file descriptor:%d\n%d\n%d\n", 100+fd, 100+fd, 100+fd);
	printf("i value is:%d\n", i);


	/* ssize_t write(int fd, const void *buf, size_t length); */
	if((retw = write(fd, writebuf, sizeof(writebuf))) < 0) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write syscall:%d\n", retw);

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);
	
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of file descriptor:%d\n", fd);

	/* ssize_t read(int fd, void *buf, size_t length); */
	if((retr = read(fd, readbuf, sizeof(writebuf))) < 0) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read syscall:%d\n", retr);
	printf("data read through read syscall:%s\n", readbuf);

	/* int fstat(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &mystat)) < 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);
	printf("\n");

	printf("************ file statistics***************\n");
	printf("ID of device containing file	:%d\n", mystat.st_dev);
	printf("Inode number		:%d\n", mystat.st_ino);
	printf("File type and mode	:%o\n", mystat.st_mode);
	printf("Number of hard links	:%d\n", mystat.st_nlink);
	printf("user ID of owner	:%d\n", mystat.st_uid);
	printf("group ID of owner	:%d\n", mystat.st_gid);
	printf("Total size in bytes	:%d\n", mystat.st_size);
	printf("Bock size for file sys	:%d\n", mystat.st_blksize);
	printf("No. of 512B blocks	:%d\n", mystat.st_blocks);
	printf("******** End of file statistics *************\n");
	printf("\n");

	return 0;
}



