#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct stat buffer;
	int fd, retwrite;
	char *mmapaddr;

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(1);
	}
	printf("file descriptor value:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count); */
	if((retwrite = write(fd, "hello bhaskar", sizeof("hello bhaskar"))) < 0)
	{
		perror("write");
		exit(1);
	}
	printf("return value of write:%d\n", retwrite);

	printf("data written to file:%s\n", system("cat bhaskar"));
	
	if(fstat(fd, &buffer) < 0)
	{
		perror("fstat");
		close(fd);
		exit(EXIT_FAILURE);
	}

	/* void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset); */
	mmapaddr = mmap(0, buffer.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(mmapaddr == MAP_FAILED)
	{
		perror("mmap");
		exit(1);
	}
	printf("address where file is mapped using mmap:%p\n", mmapaddr);

	/* char *strncpy(void *dest, const void *src, size_t n); */
	strncpy(mmapaddr, "above", 5);

	return 0;
}
