#include<stdio.h>
#include<stdlib.h>
#include<sys/signal.h>


void sigint_handler(int signum)
{
	printf("Inside sigint handler:\n");
}

int main()
{
	char name[30];
	printf("Registering signal handler function:\n");
	signal(SIGINT, sigint_handler);
	printf("Until Enter your name you can use signal");
	scanf("%s", name);
	printf("you have entered name as:%s\n", name);
	
	return 0;
}
