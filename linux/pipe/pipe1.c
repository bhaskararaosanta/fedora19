#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	char buf[20];
	int pid, pipefd[2];
	pipe(pipefd);
	pid = fork();
	if(pid == 0)
	{
		printf("return value of fork inside child process:%d\n", pid);
		close(pipefd[1]);
		read(pipefd[0], buf, sizeof("Hello world"));
		printf("data read through pipe:%s\n", buf);
	}
	else
	{
		printf("return value of fork inside parent process:%d\n", pid);
		close(pipefd[0]);
		write(pipefd[1], "Hello world", sizeof("Hello world"));
	}

	return 0;
}
