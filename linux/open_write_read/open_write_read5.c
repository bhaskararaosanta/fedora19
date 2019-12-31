#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	struct stat buf;
	int fd, retw, retr, retlseek, retc, retfstat;
	char wbuf[30] = "Embedded is best", rbuf[30];
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retw = write(fd, wbuf, sizeof(wbuf))) < 0) {
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write syscall:%d\n", retw);
	printf("Data written to file:%s\n", wbuf);

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close:%d\n", retc);

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retr = read(fd, rbuf, sizeof(rbuf))) < 0) {
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("return value of read syscall:%d\n", retr);

	/* int fstat(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &buf)) < 0) {
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close:%d\n", retc);
	printf("Data read from file:%s\n", rbuf);

	printf("******* printing file statistics **********\n");
	printf("ID of device containig file	:%d\n", buf.st_dev);
	printf("Inode number		:%d\n", buf.st_ino);
	printf("File type and mode	:%o\n", buf.st_mode);
	printf("Number of hard links	:%d\n", buf.st_nlink);
	printf("User ID of owner	:%d\n", buf.st_uid);
	printf("Group ID of owner	:%d\n", buf.st_gid);
	printf("Device ID		:%d\n", buf.st_rdev);
	printf("Total file size in bytes:%d\n", buf.st_size);
	printf("Block size of file sys	:%d\n", buf.st_blksize);
	printf("No. of 512B blocks	:%d\n", buf.st_blocks);
	printf("******* End of file statistics ***********\n");
	
	return 0;
}


