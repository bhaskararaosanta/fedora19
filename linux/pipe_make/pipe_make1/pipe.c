#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int pipefd[2], retpipe;
	pid_t pid;

	if((retpipe = pipe(pipefd)) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("return value of pipe():%d\n", retpipe);

	printf("return value of pipefd[0]:%d\n", pipefd[0]);
	printf("return value of pipefd[1]:%d\n", pipefd[1]);

	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{	
		char buf[30];
		printf("I am in child process\n");
		close(pipefd[1]); // closing write end of pipe
		read(pipefd[0], buf, sizeof("bhaskar is very good"));
		printf("data read through pipe:%s\n", buf);
		close(pipefd[0]);
	}
	else
	{
		printf("I am in parent process\n");
		close(pipefd[0]); // closing read end of pipe
		write(pipefd[1], "bhaskar is very good", sizeof("bhaskar is very good"));
		printf("data written through pipe:bhaskar is very good\n");
		close(pipefd[1]);
		sleep(3);
	}
	
	return 0;
}
