#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define	myerror(msg)	\
	do {perror(msg); exit(EXIT_FAILURE); } while(0)

int main()
{
	int fd, retwrite, retread, retlseek, retclose;
	char buf[40], buffer_extra[30] = "bhaskar is very good";

	struct stat buffer;

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		myerror("open");
	}
	printf("return value of file descriptor:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count) */
	if((retwrite = write(fd, "Embedded systems", sizeof("Embedded systems"))) < 0)
	{
		myerror("write");
	}
	printf("return value of write:%d\n", retwrite);

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		myerror("close");
	}
	printf("return value of close:%d\n", retclose);
	
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		myerror("open");
	}
	printf("return value of file descriptor:%d\n", fd);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retread = read(fd, buf, sizeof("Embedded systems"))) < 9)
	{
		myerror("read");
	}
	printf("return value of read:%d\n", retread);

	printf("data read from file is:%s\n", buf);
	
	/* off_t lseek(int fd, off_t offset, int whence); */
	if((retlseek = lseek(fd, 5, SEEK_SET)) < 0)
	{
		myerror("lseek");
	}
	printf("return value of lseek:%d\n", retlseek);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retread = read(fd, buf, sizeof("Embedded systems"))) < 9)
	{
		myerror("read");
	}
	printf("return value of read:%d\n", retread);
	
	printf("data read from file is:%s\n", buf);
	
	if(stat("bhaskar", &buffer) < 0)
        {
                myerror("stat");
        }

        printf("printing file statistics from struct stat\n");
        printf("device number:%d\n", buffer.st_dev);
        printf("File mode:%o\n", buffer.st_mode);
        printf("Link count:%d\n", buffer.st_nlink);
        printf("User id of file's owner:%d\n", buffer.st_uid);
        printf("Group id of file's group:%d\n", buffer.st_gid);
        printf("Size of file in bytes:%d\n", buffer.st_size);
        printf("Number of blocks allocated:%d\n", buffer.st_blocks);
        printf("File serial number:%d\n", buffer.st_ino);


	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		myerror("close");
	}
	printf("return value of close:%d\n", retclose);

	printf("*********again printing ****************\n");

	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		myerror("open");
	}
	printf("return value of file descriptor:%d\n", fd);

	/* ssize_t write(int fd, const void *buf, size_t count) */
	if((retwrite = write(fd, buffer_extra, sizeof("bhaskar is very good"))) < 0)
	{
		myerror("write");
	}
	printf("return value of write:%d\n", retwrite);

	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		myerror("close");
	}
	printf("return value of close:%d\n", retclose);
	
	/* int open(const char *pathname, int flags, mode_t mode); */
	if((fd = open("bhaskar", O_CREAT | O_RDWR, 0666)) < 0)
	{
		myerror("open");
	}
	printf("return value of file descriptor:%d\n", fd);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retread = read(fd, buf, sizeof("bhaskar is very good"))) < 9)
	{
		myerror("read");
	}
	printf("return value of read:%d\n", retread);

	printf("data read from file is:%s\n", buf);
	
	/* off_t lseek(int fd, off_t offset, int whence); */
	if((retlseek = lseek(fd, 5, SEEK_SET)) < 0)
	{
		myerror("lseek");
	}
	printf("return value of lseek:%d\n", retlseek);

	/* ssize_t read(int fd, void *buf, size_t count); */
	if((retread = read(fd, buf, sizeof("bhaskar is very good"))) < 9)
	{
		myerror("read");
	}
	printf("return value of read:%d\n", retread);
	
	printf("data read from file is:%s\n", buf);
	
	if(stat("bhaskar", &buffer) < 0)
        {
                myerror("stat");
        }

        printf("printing file statistics from struct stat\n");
        printf("device number:%d\n", buffer.st_dev);
        printf("File mode:%o\n", buffer.st_mode);
        printf("Link count:%d\n", buffer.st_nlink);
        printf("User id of file's owner:%d\n", buffer.st_uid);
        printf("Group id of file's group:%d\n", buffer.st_gid);
        printf("Size of file in bytes:%d\n", buffer.st_size);
        printf("Number of blocks allocated:%d\n", buffer.st_blocks);
        printf("File serial number:%d\n", buffer.st_ino);


	/* int close(int fd); */
	if((retclose = close(fd)) < 0)
	{
		myerror("close");
	}
	printf("return value of close:%d\n", retclose);

		
	return 0;
}
