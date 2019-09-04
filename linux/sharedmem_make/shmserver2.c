#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct shmshare{
	int data;
	char name[30];
};

int main()
{
	struct shmshare *shmserver;
	key_t key;
	int shmid, retshmat;

	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0)
	{
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", key);

	/* int shmget(key_t key, size_t shmsz, int shmflg); */
	if((shmid = shmget(key, sizeof(struct shmshare), IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Shared memory id:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shmserver = (struct shmshare *)shmat(shmid, 0, 0666)) == (struct shmshare *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("the memory location where shared memory attached:%p\n", shmserver);

	printf("Writing data into the shared memory as follows:\n");
	shmserver->data = 100;
	strcpy(shmserver->name, "Bhaskar is a good boy");
	printf("data item entered in shared memory:%d\n", shmserver->data);
	printf("name item entered in shared memory:%s\n", shmserver->name);

	return 0;
}

