#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int fd, retfstat, retwrite;
	char *mmapbuf;

	struct stat mystat;

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR | O_SYNC, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retwrite = write(fd, "Hello world", sizeof("Hello world"))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write:%d\n", retwrite);

	/* int fstat(int fd, struct stat *buf); */
	if((retfstat = fstat(fd, &mystat)) < 0)
	{
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);
	
	/* void *mmap(void *addr, size_t length, int prot, int flas, inf fd, off_t offset); */
	mmapbuf = mmap(NULL, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(mmapbuf == MAP_FAILED)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("memory where mapped the file using mmap:%p\n", mmapbuf);

	/* char *strncpy(char *dest, const char *src, size_t n); */
	strncpy(mmapbuf, "bhaskar", 8);
	
	printf("********** printing file statistics **********\n");
	printf("ID of device containing file:%d\n", mystat.st_dev);
	printf("inode number:%d\n", mystat.st_ino);
        printf("file type and mode:%o\n", mystat.st_mode);
	printf("number of hard links:%d\n", mystat.st_nlink);
        printf("user ID of owner:%d\n", mystat.st_uid);
        printf("group ID of owner:%d\n", mystat.st_gid);
        printf("total size, in bytes:%d\n", mystat.st_size);
 	printf("blocksize for filesystem I/O:%d\n", mystat.st_blksize);
	printf("number of 512B blocks allocated:%d\n", mystat.st_blocks);

	return 0;
}

