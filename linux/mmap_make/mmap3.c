#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

int main()
{
	struct stat buffer;
	int fd, retwrite, retfstat;
	void *mmapaddr;
	
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retwrite = write(fd, "hello world", sizeof("hello world"))) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	printf("return value of write:%d\n", retwrite);

	/* int fstat(int fd, struct stat *statbuf); */
	if((retfstat = fstat(fd, &buffer)) < 0)
	{
		perror("fstat");
		exit(EXIT_FAILURE);
	}
	printf("return value of fstat:%d\n", retfstat);

	printf("printing file statistics:\n");
	
        printf("ID of device containing file :%d\n", buffer.st_dev);
	printf("Inode number			:%d\n", buffer.st_ino);
        printf("File type and mode:		:%o\n", buffer.st_mode);
        printf("Number of hard links		:%d\n", buffer.st_nlink);
        printf("User ID of owner		:%d\n", buffer.st_uid);
        printf("Group ID of owner		:%d\n", buffer.st_gid);
        printf("Total size, in bytes		:%d\n", buffer.st_size);
        printf("Block size for filesystem I/O:%d\n", buffer.st_blksize);
	printf("Number of 512B blocks allocated:%d\n", buffer.st_blocks);

	/* void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset); */
	mmapaddr = mmap(NULL, buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(mmapaddr == MAP_FAILED)
	{
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("memory address location mapped by mmap:%p\n", mmapaddr);

	/* char *strncpy(char *dest, const char *src, size_t n); */
	strncpy(mmapaddr, "Bello", 5);

	return 0;
}

