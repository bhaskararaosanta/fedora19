#include<stdio.h>
#include<stdlib.h>
#include<sys/signal.h>
#include<unistd.h>


void signal_handler(int signum)
{
	if(signum == SIGINT)
	{
		printf("Inside sigint handler:\n");
	}
	else if(signum == SIGALRM)
	{
		printf("Inside sigalrm handler:\n");
	}
}

int main()
{
	char name[30];
	printf("Registering signal handler function:\n");
	signal(SIGINT, signal_handler);
	signal(SIGALRM, signal_handler);
	alarm(5);
	printf("Until Enter your name you can use signal");
	scanf("%s", name);
	printf("you have entered name as:%s\n", name);
	
	return 0;
}
