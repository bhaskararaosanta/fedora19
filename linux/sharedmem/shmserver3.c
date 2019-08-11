
#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

#define	SHMSIZE	27

int main()
{
	int i, key = ftok(".", 'a');
	char *shm, *s;
	int shmid;

	printf("Value of key:%d\n", key);

	if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Value of shmid:%d\n", shmid);

	if((shm = shmat(shmid, 0, 0666)) == (char *)0)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 27; i++)
	{
		printf("garbage values stored at shared memory locations:%c\n", *shm++);
	}


	return 0;
}
