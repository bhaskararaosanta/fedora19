#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	
	char buffer[20];
	int ret, fd, retmkfifo;
	retmkfifo = mkfifo("./myfifo", 0777);
	ret = fork();
	if(ret == 0)
	{
	printf("Return value of mkfifo:%d\n", retmkfifo);
	
	fd = open("./myfifo", O_WRONLY, 0777);
	write(fd, "Hello world", sizeof("Hello world"));
	close(fd);
	}
	else
	{
	fd = open("./myfifo", O_RDONLY, 0777);
	read(fd, buffer, sizeof("Hello world"));
	close(fd);
	printf("data read is:%s\n", buffer);
	}

	return 0;
}


