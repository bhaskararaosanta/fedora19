#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd;
	void *buf;
	struct stat mystat;

	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0777)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	if(write(fd, "hello embedded", sizeof("hello embedded")) < 0)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}

	if(fstat(fd, &mystat) < 0)
	{
		perror("fstat");
		close(fd);
		exit(EXIT_FAILURE);
	}

	buf = mmap(NULL, mystat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(buf == MAP_FAILED)
	{
		perror("mmap");
		close(fd);
		exit(EXIT_FAILURE);
	}
	printf("memory location where mmap mapped file descriptor:%p\n", buf);


	strncpy(buf, "Navaa", 5);

	return 0;
}
