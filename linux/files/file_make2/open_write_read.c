#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	struct stat buf;
	int fd, retw, retlseek, retr, retc, retfs;
	char wbuf[40] = "Embedded world is great", rbuf[40];

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(1);
	}
	printf("File descriptor value:%d\n", fd);
	
	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retw = write(fd, wbuf, sizeof(wbuf))) < 0)
	{
		perror("write");
		exit(1);
	}
	printf("Return value of write:%d\n", retw);
	printf("data written to file using fd:%s\n", wbuf);

	/* int close(int fd); */
	if((retc = close(fd)) < 0 )
	{
		perror("close");
		exit(1);
	}
	printf("return value of close;%d\n", retc);

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_RDONLY, 0666)) < 0)
	{
		perror("open");
		exit(1);
	}
	printf("File descriptor value:%d\n", fd);
	
	/* int fstat(int fd, struct stat *buf); */
	if((retfs = fstat(fd, &buf)) < 0)
	{
		perror("fstat");
		exit(1);
	}
	printf("return value of fstat:%d\n", retfs);
	
	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retr = read(fd, rbuf, sizeof(wbuf))) < 0)
	{
		perror("read");
		exit(1);
	}
	printf("Return value of read:%d\n", retr);
	printf("data read from file using fd:%s\n", rbuf);

	printf("********* file statistics begin ****************\n");

	printf("ID of device containing file		:%d\n", buf.st_dev);
	printf("Inode number				:%d\n", buf.st_ino);
	printf("file type and mode			:%o\n", buf.st_mode);
	printf("number of hard links			:%d\n", buf.st_nlink);
	printf("user ID of owner			:%d\n", buf.st_uid);
	printf("group ID of owner			:%d\n", buf.st_gid);
	printf("device ID (in case special file)	:%d\n", buf.st_rdev);
	printf("total size in bytes			:%d\n", buf.st_size);
	printf("block size for file system I/O		:%d\n", buf.st_blksize);
	printf("number of 512B blocks assigned		:%d\n", buf.st_blocks);

	printf("time of last access			:%s\n", ctime(&buf.st_atim.tv_sec));
	printf("time of last modification		:%s\n", ctime(&buf.st_mtim.tv_sec));
	printf("time of last status change		:%s\n", ctime(&buf.st_ctim.tv_sec));

	printf("******** file statistics end ****************\n");

	/* int close(int fd); */
	if((retc = close(fd)) < 0 )
	{
		perror("close");
		exit(1);
	}
	printf("return value of close;%d\n", retc);

	return 0;
}
