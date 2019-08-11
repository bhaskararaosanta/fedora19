#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/types.h>

#define	SHMSIZE	27

int main()
{
	key_t key = ftok(".", 'a');
	int shmid;
	char c, *shm, *s;

	printf("return value of key:%d\n", (int)key);

	/* int shmget(key_t key, size_t size, int shmflg); */
	if((shmid = shmget(key, SHMSIZE, 0666)) < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmget or shared memory id:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shm = shmat(shmid, NULL, 0666)) == (char *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	
	printf("address of shared memory:%p and its value at first location:%d\n", shm, *shm);

	s = shm;

	printf("values stored in shared memory using server process:");
	for(c = 'a'; c <= 'z'; c++)
	{
		printf("%c ", *s);
		s++;
	}

	printf("\n");

	*shm = '*'; /* waiting server process until this client process changes 
			       first character from 'a' to '*' */

	return 0;
}

