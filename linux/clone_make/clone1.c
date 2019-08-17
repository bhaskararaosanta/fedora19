#define	_GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


#define STACKSIZE	(1024 * 1024)

int child_proc(void *arg)
{
	printf("Child process arg = %s\n", (char *)arg);
	sleep(2);
	return 0;
}

int main(int argc, char *argv[])
{

	char *stack;
	char *stackhead;

	char *str = "Hello world\n";

	pid_t pid;
	int status;

	stack = (char *)malloc(STACKSIZE);
	if(!stack)
	{
		fprintf(stderr, "unable to allocate stack.\n");
		exit(EXIT_FAILURE);
	}

	stackhead = stack + STACKSIZE - 1;
	printf("Parent pid = %d\n", getpid());
	pid = clone(child_proc, stackhead, SIGCHLD, str);
	if(pid == -1)
	{
		fprintf(stderr, "unable to clone process.\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	printf("Child pid = %d\n", pid);
	waitpid(pid, &status, 0);

	return 0;
}	
