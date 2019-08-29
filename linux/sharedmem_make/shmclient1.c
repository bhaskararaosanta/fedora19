#include <stdio.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct share{
	int age;
	char name[20];
} *shm_at, *shm_dt;

int main()
{
	struct shmid_ds stat;
	int shmid, retshmctl;
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
	
	printf("Data reading from shared memory in client program is equal to age = 100, name = bhaskar.\n");
	printf("age is:%d\n", shm_at->age);
	printf("name is:%s\n", shm_at->name);

	if((retshmctl = shmctl(shmid, IPC_STAT, &stat)) < 0)
	{
		perror("shmctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmctl:%d\n", retshmctl);

	printf("printing values from shared memory kernel data structure.\n");

	printf("shared memory segment size:%d\n", (int)stat.shm_segsz);
	printf("shared memory last attach time:%s\n", ctime(&stat.shm_atime));
	printf("no. of current attaches:%d\n", stat.shm_nattch);

	return 0;
}
