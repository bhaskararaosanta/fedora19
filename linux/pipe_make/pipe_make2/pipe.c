#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
	int pipefd[2], retwrite, retread, retclose;
	char buf[20];

	/* int pipe(int pipefd[2]); */
	pipe(pipefd);
	printf("return value of read end descriptor:%d\n", pipefd[0]);
	printf("return value of write end descriptor:%d\n", pipefd[1]);

	if(fork() == 0)
	{
		printf("I am in child process with pid:%d\n", getpid());
		printf("I am in child process with child's parent pid:%d\n", getppid());
		close(pipefd[1]); // closing write end of pipe
		read(pipefd[0], buf, sizeof("hello world"));
		close(pipefd[0]);
		printf("data read from parent to child using pipe:%s\n", buf);
	}
	else
	{
		printf("I am in parent process with pid:%d\n", getpid());
		printf("I am in parent process with paren't parent pid:%d\n", getppid());
		close(pipefd[0]); // closing read end of pipe
		write(pipefd[1], "hello world", sizeof("hello world"));
		close(pipefd[1]);
		printf("data write from parent to child using pipe:hello world\n");
	}

	return 0;
}

