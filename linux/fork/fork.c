#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	fork();
	fork();
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		for(int i = 0; i < 1; i++)
		{	
			fork();
			printf("I am in child process with pid:%d\n", getpid());
			//printf("I am in child process with my parent process id:%d\n", getppid());
			//sleep(3);
		}
	}
	else
	{
		for(int i = 0; i < 1; i++)
		{
			//rk();
			printf("I am in parent process with pid:%d\n", getpid());
			//printf("I am in parent process with my parent process id:%d\n", getppid());
			//sleep(3);
		}
	}
	
	return 0;
}	

