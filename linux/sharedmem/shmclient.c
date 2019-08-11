#include<stdio.h>
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
	printf("value of key generated:%d\n", (int)key);

	if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}
	printf("value of shmid is:%d\n", shmid);

	if((shm = shmat(shmid, NULL, 0)) == (char *)-1)
	{
		perror("shmat");
		exit(1);
	}
	s = shm;
	for( ; *s != '\0'; s++)
	{
		printf("data at shared memory:%c\t", *s);
	}
	*shm = '*';
	printf("released the server process due to client modified 1st memory data:\n");

	return 0;
}
