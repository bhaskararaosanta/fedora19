#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>

#define	SHMSIZE	27

int main()
{
	int shmid;
	char *shm, *s, c;
	key_t key = ftok(".", 'a');
	printf("Value of key:%d\n", key);

	if((shmid = shmget(key, SHMSIZE, 0666)) < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory segment ID:%d\n", shmid);

	if((shm = shmat(shmid, 0, 0)) == (char *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("Address at which memory segment attached:%p\n", shm);
	
	s = shm;

	while(*s != '\0')
	{
		printf("content stored at share memory:%c\n", *s);
		s++;
	}
	printf("server process will wait until this process change shared segment first location to '*':\n");
	*shm = '*';

	return 0;
}



