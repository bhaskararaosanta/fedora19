#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t thread1, thread2;
pthread_attr_t attr1, attr2;

void *thread1_handler(void *arg1)
{
	printf("I am in thread1 routine.\n");
	printf("arg received by thread1:%d\n", *(int *)arg1);
	pthread_exit(&thread1);
	//return;
}

void *thread2_handler(void *arg2)
{
	printf("I am in thread2 routine.\n");
	printf("arg received by thread2:%d\n", *(int *)arg2);
	pthread_exit(&thread2);
	//return;
}

int main()
{
	int a = 10, b =20;
	int tid1, tid2, *ptr1, *ptr2;
	ptr1 = &a;
	ptr2 = &b;
	/* int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
	 * 			void *(*start_routine) (void *), void *arg); */
	if((tid1 = pthread_create(&thread1, &attr1, thread1_handler, &ptr1)) < 0)
	{
		perror("pthread_create");
		exit(1);
	}
	printf("return value of pthread_create:%d\n", tid1);

	if((tid2 = pthread_create(&thread2, &attr2, thread2_handler, &ptr2)) < 0)
	{
		perror("pthread_create");
		exit(1);
	}
	printf("return value of pthread_create:%d\n", tid2);

	pthread_join(&thread1, NULL);
	pthread_join(&thread2, NULL);

	return 0;
}

