#define	_GNU_SOURCE

#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int fn(void *arg)
{
	printf("Info: This code is running from child process with pid:%d\n", getpid());

	int i = 0;
	int n = atoi(arg);
	for(i = 0; i <= 20; i++)
	{
		printf("%d  x  %d =  %d\n", n, i, (n * i));
	}
	printf("\n");
	_exit(0);
}

int main(int argc, char *argv[])
{
	printf("Hello World.\n");

	void *child_stack = malloc(1024 * 1024);
	if(child_stack == NULL)
	{
		printf("Error: unable to allocate child stack memory.\n");
		exit(EXIT_FAILURE);
	}

	int pid = clone(fn, child_stack + (1024*1024), SIGCHLD, argv[1]);
	if(pid < 0)
	{
		printf("Error: Unable to create the child process.\n");
		exit(EXIT_FAILURE);
	}
	printf("Return value of clone:%d\n", pid);
	wait(NULL);
	free(child_stack);
	printf("child process terminated successfully and this message from parent or calling process.\n");

	return 0;
}
