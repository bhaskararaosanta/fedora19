#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>

int main()
{
	struct stat mystat;
	void *buf;
	int fd, retwrite;

	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	printf("return value of fd:%d\n", fd);

	if((retwrite = write(fd, "hello embedded", sizeof("hello embedded"))) < 0)
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
	
	printf("memory location where mapped the file:%p\n", buf);
	
	strncpy(buf, "bhaskar", 7);

	return 0;
}

