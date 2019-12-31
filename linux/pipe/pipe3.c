#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
	int pipefd[2], pid, retpipe;
	char wbuf[30] = "Embedded is best", rbuf[30];
	/* int pipe(int pipefd[2]); */
	if((retpipe = pipe(pipefd)) < 0) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	printf("pipe descriptors:%d\t%d\n", pipefd[0], pipefd[1]);
	/* int fork(void); */
	pid =fork();
	if(pid < 0) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0) {
		printf("I am in child process\n");
		close(pipefd[1]); // closing write end of pipe
		read(pipefd[0], rbuf, sizeof(rbuf));
		printf("data read through pipe is:%s\n", rbuf);
		close(pipefd[0]);
	}
	else {
		printf("I am in parent process\n");
		close(pipefd[0]); // closing read end of pipe
		write(pipefd[1], wbuf, sizeof(wbuf));
		printf("data written to pipe is:%s\n", wbuf);
		close(pipefd[1]);
	}

	return 0;
}



