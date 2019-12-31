#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	struct stat buf;
	char wbuf[30] = "Embedded is great", rbuf[30];
	int fd, retw, retr, retc, retfstat, retlseek;
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_WRONLY, 0666)) < 0) {
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* int write(int fd, const void *buf, size_t size); */
	if((retw = write(fd, wbuf, sizeof(wbuf))) < 0) {
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
	printf("return value of fd:%d\n", fd);

	/* ssize_t read(int fd, void *buf, size_t size); */
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
	printf("Return value of fstat syscall:%d\n", retfstat);

	printf("data read from file descriptor:%s\n", rbuf);

	/* int close(int fd); */
	if((retc = close(fd)) < 0) {
		perror("close");
		exit(EXIT_FAILURE);
	}
	printf("return value of close syscall:%d\n", retc);

	printf(" ********* printing file statistics **************\n");
	printf("ID of device containing file	:%d\n", buf.st_dev);
	printf("Inode number			:%d\n", buf.st_ino);
	printf("File type and mode		:%o\n", buf.st_mode);
	printf("Number of hard links		:%d\n", buf.st_nlink);
	printf("User ID of owner		:%d\n", buf.st_uid);
	printf("Group ID of owner		:%d\n", buf.st_gid);
	printf("Total size in bytes		:%d\n", buf.st_size);
	printf("Block size for file system I/O	:%d\n", buf.st_blksize);
	printf("No. of 512B blocks allocated	:%d\n", buf.st_blocks);
	printf(" ****** end of printing files stats **************\n");

	return 0;
}
