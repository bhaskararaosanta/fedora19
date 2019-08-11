#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int main()
{
	char buffer[10];
	int pipe_fd[2];

	pipe(pipe_fd);
	if(fork() == 0)
	{
		close(pipe_fd[1]);
		printf("child process is reading from the pipe:\n");
		read(pipe_fd[0], buffer, 10);
		printf("Data read is:%s\n", buffer);
	}
	else
	{
		close(pipe_fd[0]);
		printf("Parent process is writing to the pipe:\n");
		write(pipe_fd[1], "pipe data", 10);
	}
	return 0;
}

