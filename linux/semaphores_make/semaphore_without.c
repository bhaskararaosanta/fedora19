#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int pid;
	pid = fork();
	srand(pid);
	if(pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid)
	{
		char *s = "abcdefgh";
		int i, l = strlen(s);
		for(i = 0; i < l; i++)
		{
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
		}
	}
	else
	{
		char *s = "ABCDEFGH";
		int i, l = strlen(s);
		for(i = 0; i < l; i++)
		{
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			sleep(rand() % 2);
		}
	}
	
	return 0;
}
