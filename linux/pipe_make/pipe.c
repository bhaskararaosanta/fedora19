#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
	int pipefd[2], status, retpipe, retwrite, retread, retclose;
	char readbuf[20], writebuf[20] = "Hello, how are you";
	pid_t pid;

	/* int pipe(int pipefd[2]); */
	if((retpipe = pipe(pipefd)) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("return value of pipe:%d\n", retpipe);
	printf("return value of read end descriptor:%d\n", pipefd[0]);
	printf("return value of write end descriptor:%d\n", pipefd[1]);

	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if(pid == 0)
	{
		printf("I am in child process.\n");
		close(pipefd[1]); /* closing unwanted write end of pipe */
		if((retread = read(pipefd[0], readbuf, strlen(writebuf))) < 0)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		readbuf[strlen(writebuf)] = '\0';
		printf("data read from pipe is:%s\n", readbuf);
	}
	else
	{
		printf("I am in parent process.\n");
		close(pipefd[0]); /* closing unwanted read end of pipe */
		if((retwrite = write(pipefd[1], writebuf, strlen(writebuf))) < 0)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
		wait(&status);
		printf("parent process successfully completed.\n");
	}

	return 0;
}



