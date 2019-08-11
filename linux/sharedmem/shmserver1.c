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

	if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
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

	for(c = 'a'; c <= 'z'; c++)
	{
		*s = c;
		s++;
	}
	printf("wait this process until client process change first location to '*':\n");
	while(*shm != '*');

	return 0;
}



