#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>

struct shmshare{
	int data;
	char name[30];
};

int main()
{
	struct shmshare *shmclient;
	struct shmid_ds buffer;
	key_t key;
	int shmid, retshmat, retshmctl;

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
	if((shmclient = (struct shmshare *)shmat(shmid, 0, 0666)) == (struct shmshare *)-1)
	{
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("the memory location where shared memory attached:%p\n", shmclient);

	printf("Reading data from the shared memory as follows:\n");
	printf("data item from shared memory:%d\n", shmclient->data);
	printf("name item from shared memory:%s\n", shmclient->name);

	/*int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
	if((retshmctl = shmctl(shmid, IPC_STAT, &buffer)) < 0)
	{
		perror("shmctl");
		exit(EXIT_FAILURE);
	}
	printf("Return value of shmctl:%d\n", retshmctl);
	
	printf("Values printing from shared memory kernel structure as follows:\n");
	printf("Size of segment (bytes):%d\n", buffer.shm_segsz);
        printf("Last attach time:%s\n", ctime(&buffer.shm_atime));
        printf("Last detach time:%s\n", ctime(&buffer.shm_dtime));
        printf("Last change time:%s\n", ctime(&buffer.shm_ctime));
        printf("PID of creator:%d\n", buffer.shm_cpid);
        printf("PID of last shmat()/shmdt():%d\n", buffer.shm_lpid);
        printf("No. of current attaches:%d\n", buffer.shm_nattch);

	printf("Key supplied to shmget(2):%d\n", buffer.shm_perm.__key);
        printf("Effective UID of owner:%d\n", buffer.shm_perm.uid);
        printf("Effective GID of owner:%d\n", buffer.shm_perm.gid);
	printf("Effective UID of creator:%d\n", buffer.shm_perm.cuid);
        printf("Effective GID of creator:%d\n", buffer.shm_perm.cgid);
        printf("Permissions + SHM_DEST and SHM_LOCKED flags:%o\n", buffer.shm_perm.mode);
        printf("Sequence number:%d\n", buffer.shm_perm.__seq);

	return 0;
}

