#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define	SHMSIZE	27

int main()
{
	struct shmid_ds bufcopy;

	key_t key = ftok(".", 'a');
	int shmid, retshmctl;
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

	printf("shmclient process id:%d\n", getpid());

	printf("\n");

	*shm = '*'; /* waiting server process until this client process changes 
			       first character from 'a' to '*' */
	
	printf("************shmctl demo**********\n");

	/* int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
	if((retshmctl = shmctl(shmid, IPC_STAT, &bufcopy)) < 0)
	{
		perror("shmctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmctl:%d\n", retshmctl);

	printf("Shared memory structure members printing from kernel using bufcopy structure pointer.\n");

	printf("shared memory segment size:%d\n", bufcopy.shm_segsz);
	printf("shared memory last attach time:%s\n", ctime(&bufcopy.shm_atime));
	printf("shared memory last detach time:%s\n", ctime(&bufcopy.shm_dtime));
	printf("shared memory last change time using shmctl:%s\n", ctime(&bufcopy.shm_ctime));
	printf("shared memory creator pid:%d\n", bufcopy.shm_cpid);
	printf("shared memory last operated process pid:%d\n", bufcopy.shm_lpid);
	printf("shared memory number of current attaches:%d\n", bufcopy.shm_nattch);
	
	printf("shared memory effective UID of owner:%d\n", bufcopy.shm_perm.uid);
	printf("shared memory effective GID of owner:%d\n", bufcopy.shm_perm.gid);
	printf("shared memory effective UID of creator:%d\n", bufcopy.shm_perm.cuid);
	printf("shared memory effective GID of creator:%d\n", bufcopy.shm_perm.cgid);
	printf("shared memory segment permissions+SHM_DEST+SHM_LOCKED flags:%o\n", bufcopy.shm_perm.mode);
	printf("shared memory sequence number:%d\n", bufcopy.shm_perm.__seq);
	return 0;
}

