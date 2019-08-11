#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
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

	if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Value of shmid:%d\n", shmid);

	if((shm = shmat(shmid, NULL, 0)) == (char *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("Memory at which shared memory attached:%p\n", shm);

	s = shm;

	for(c = 'a'; c <= 'z'; c++)
	{
		*s++ = c;
	}

	while(*shm != '*');

	return 0;
}
