#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int pipefd[2];
	pid_t cpid;
	char buf;

	if(argc != 2)
	{
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if((pipe(pipefd)) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	cpid = fork();
	if(cpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if(cpid == 0)	/* child reads from pipe */
	{
		close(pipefd[1]);	/* close unused write end for pipe */
		while((read(pipefd[0], &buf, 1)) > 0)
			write(STDOUT_FILENO, &buf, 1);
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	}

	else		/* parent writes argv[1] to pipe */
	{
		close(pipefd[0]);	/* close unused read end for pipe */
		write(pipefd[1], argv[1], sizeof(argv[1]));
		close(pipefd[1]);	/* reader will see EOF */
		wait(NULL);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
