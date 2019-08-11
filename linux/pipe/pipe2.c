#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
	char a[20];
	int pipefd[2], retpipe, retfork;
	/* pipe: int pipe(int pipefd[2]); */
	if((retpipe = pipe(pipefd)) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("return value of pipe:%d\n", retpipe);

	if((retfork = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(retfork == 0)
	{
		close(pipefd[1]);
		read(pipefd[0], a, sizeof("Hello world"));
		a[15] = '\0';
		printf("data read from parent to child process is:%s\n", a);
	}
	else
	{
		close(pipefd[0]);
		write(pipefd[1], "hello world", sizeof("hello world"));
		printf("data written to child proces is:hello world\n");
	}

	return 0;
}
