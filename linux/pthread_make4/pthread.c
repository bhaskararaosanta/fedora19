#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

pthread_t thread1;
pthread_t thread2;

void thread1_main(void);
void thread2_main(void);

void sig_handler(int signum)
{
	if(signum != SIGINT) {
		printf("received invalid signum = %d\n", signum);
		exit(1);
	}
	printf("received SIGINT and exiting application.\n");

	exit(0);
}

int main()
{
	pthread_attr_t attr;
	int status;

	signal(SIGINT, sig_handler);
	
	pthread_attr_init(&attr);
	pthread_attr_setstacksize(&attr, 1024 * 1024);

	printf("creating thread1.\n");
	status = pthread_create(&thread1, &attr, (void *)&thread1_main, NULL);
	if(status != 0)
	{
		printf("Failed to create thread1 with status = %d\n", status);
		exit(1);
	}

	printf("creating thread2.\n");
	status = pthread_create(&thread2, &attr, (void *)&thread2_main, NULL);
	if(status != 0)
	{
		printf("Failed to create thread2 with status = %d\n", status);
		exit(1);
	}

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sig_handler(SIGINT);

	return 0;
}

void thread1_main(void)
{
	unsigned int run_count;
	unsigned int execution_period_usecs;
	struct timeval ts;
	
	execution_period_usecs = 1;

	printf("Thread1 started. Execution period = %d usecs\n", execution_period_usecs);

	run_count = 0;
	while(1)
	{
		sleep(1);
		gettimeofday(&ts, NULL);
		printf("%06lu.%06lu:----Thread1 run_count = %d ----\n", \
				(unsigned int)ts.tv_sec, (unsigned int)ts.tv_usec, run_count);
		run_count += 1;
	}
}

void thread2_main(void)
{
	unsigned int run_count;
	unsigned int execution_period_usecs;
	struct timeval ts;
	
	execution_period_usecs = 5;

	printf("Thread2 started. Execution period = %d usecs\n", execution_period_usecs);

	run_count = 0;
	while(1)
	{
		sleep(5);
		gettimeofday(&ts, NULL);
		printf("%06lu.%06lu:----Thread2 run_count = %d ----\n", \
				(unsigned int)ts.tv_sec, (unsigned int)ts.tv_usec, run_count);
		run_count += 1;
	}
}
