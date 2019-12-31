#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t cpid;
	/* pid_t fork(void); */
	cpid = fork();
	switch(cpid)
	{
		case -1:printf("Exiting because fork system call failed\n");
			exit(EXIT_FAILURE);

		case 0: printf("return value of fork to child process:%d\n", cpid);
			printf("I am in child process with pid:%d\n", getpid());
			printf("I am in child process with parent pid:%d\n", getppid());
			break;

		default:printf("return value of fork to parent process:%d\n", cpid);
			printf("I am in parent process with pid:%d\n", getpid());
			printf("I am in parent process with parent pid:%d\n", getppid());
			break;
	}

	return 0;
}


