#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <stdlib.h>

#define	perror(msg)	do{perror(msg); exit(EXIT_FAILURE);}while(0)
int main()
{
	int fd, retwrite, retread, retclose, retflock, retlseek;
	char buf[30];

	/* int open(int fd, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		perror("open");
	}
	printf("retrn value of fd:%d\n", fd);

	/* int flock(int fd, int operation); */
	if((retflock = flock(fd, LOCK_EX)) < 0)
	{
		perror("flock");
	}
	printf("return value of flock:%d\n", retflock);

	/* ssize_t write(int fd, const char*buf, size_t count); */
	if((retwrite = write(fd, "Hello world", sizeof("Hello world"))) < 9)
	{
		perror("write");
	}
	printf("return value of write:%d\n", retwrite);

/*	#error	bhaskar its a test error pragma to see the compilation stops here */

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		perror("close");
	}
	printf("return value of close:%d\n", retclose);

	/* int open(int fd, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_RDONLY, 0666)) < 0)
	{
		perror("open");
	}
	printf("retrn value of fd:%d\n", fd);

	//sleep(120); // To hold the lock by this process about 120 seconds

	/* ssize_t write(int fd, char*buf, size_t count); */
	if((retread = read(fd, buf, sizeof("Hello world"))) < 9)
	{
		perror("read");
	}
	printf("return value of read:%d\n", retread);

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		perror("close");
	}
	printf("return value of close:%d\n", retclose);
	printf("data read from file is:%s\n", buf);

	return 0;
}

