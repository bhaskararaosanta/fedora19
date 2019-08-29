#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int retpipe, pipefd[2];
	printf("pipefd array values befor pipe system call:%d and %d\n", pipefd[0], pipefd[1]);
	char buf[10];

	/* int pipe(int pipefd[2]); */
	if((retpipe = pipe(pipefd)) < 0)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("Return value of pipe() is:%d\n", retpipe);
	printf("pipefd array values or pipe descriptors after pipe system call:%d and %d\n", pipefd[0], pipefd[1]);

	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		close(pipefd[1]); // closing write end of pipe
		read(pipefd[0], buf, sizeof("Hello world"));
		close(pipefd[0]);
		printf("data read through pipe is:%s\n", buf);
	}
	else
	{
		close(pipefd[0]); // closing read end of pipe
		write(pipefd[1], "Hello world", sizeof("Hello world"));
		close(pipefd[1]);
	}

	return 0;
}

