#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>

struct share{
	int age;
	char name[20];
} *shm_at;

int main()
{
	int shmid;
	key_t key;

	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0)
	{
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", (int)key);

	/* int shmget(key_t key, size_t size, int shmflg); */
	if((shmid = shmget(key, sizeof(struct share), IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("shared memory segment id:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if(((shm_at = (struct share *)shmat(shmid, NULL, 0))) == (struct share *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("Memory location where shared memory is attached:%p\n", shm_at);
	
	printf("Data written to shared memory is age = 100, name = bhaskar.\n");
	shm_at->age = 100;
	strcpy(shm_at->name, "bhaskar");

	return 0;
}
