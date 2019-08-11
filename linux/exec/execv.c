#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid == 0)
	{
		printf("I am in child process:\n");
		execv("./hello", NULL);
		printf("This statement after exec sys call never executes:\n");
	}
	else
	{
		printf("I am in parent process:\n");
	}

	return 0;
}
