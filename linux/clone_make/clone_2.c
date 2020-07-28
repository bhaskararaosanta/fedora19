#define	_GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

#define	STACK_SIZE	(1024*1024)

int child_proc(void *arg)
{
	printf("Child process arg = %s\n", (char *)arg);
	sleep(2);
	return 0;
}

int main()
{
	char *stack;
	char *stackhead;

	char *str = "Hello World\n";

	pid_t pid;
	int status;

	stack = (char *)malloc(STACK_SIZE);
	if(!stack) {
		fprintf(stderr, "Unable to allocate stack.\n");
		exit(EXIT_FAILURE);
	}

	stackhead = stack + STACK_SIZE - 1;
	printf("Parent pid = %d\n", getpid());
	
	/* int clone(int (*fn)(void *), void *child_stack, int flags, void *arg, ...); */
	pid = clone(child_proc, stackhead, SIGCHLD, str);
	if(pid == -1) {
		fprintf(stderr, "Unable to clone process.\n");
		free(stack);
		exit(EXIT_FAILURE);
	}

	printf("child pid = %d\n", pid);
	waitpid(pid, &status, 0);

	return 0;
}

