#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct shmbuf {
	int age;
	char data[50];
};

int main()
{
	struct shmbuf *shmclient;
	struct shmid_ds buf;
//	struct shminfo buf2;
	int shmid, retshmctl;
	key_t key;

	if((key = ftok(".", 'a')) < 0)
	{
		perror("ftok");
		exit(1);
	}
	printf("return value of key:%d\n", key);

	/* int shmget(key_t key, size_t size, int shmflg); */
	if((shmid = shmget(key, sizeof(struct shmbuf), IPC_CREAT | 0666)) < 0)
	{
		perror("shmget");
		exit(1);
	}
	printf("return value of shmid:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	if((shmclient = (struct shmbuf *)shmat(shmid, 0, 0)) == (struct shmbuf *)-1)
	{
		perror("shmat");
		exit(1);
	}
	printf("memory location where shared memory attached:%p\n", shmclient);

	/* int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
	if((retshmctl = shmctl(shmid, IPC_STAT, &buf)) < 0)
	{
		perror("shmctl");
		exit(1);
	}
	printf("return value of shmctl:%d\n", retshmctl);

	printf("data received from shared memory:%d\n", shmclient->age);
	printf("data received from shared memory:%s\n", shmclient->data);

	printf("*********** printing sharedmem stats **********\n");

	struct ipc_perm shm_perm;    /* Ownership and permissions */
	printf("Size of segment (bytes):%d\n", buf.shm_segsz);
        printf("Last attach time	:%s\n", ctime(&buf.shm_atime));
        printf("Last detach time	:%s\n", ctime(&buf.shm_dtime));
        printf("Last change time	:%s\n", ctime(&buf.shm_ctime));
	printf("PID of creator		:%d\n", buf.shm_cpid);
	printf("PID of last shmat(2)/shmdt(2) :%d\n", buf.shm_lpid);
	printf("No. of current attaches	:%d\n", buf.shm_nattch);

     	printf("Key supplied to shmget(2):%d\n", buf.shm_perm.__key);
	printf("Effective UID of owner	:%d\n", buf.shm_perm.uid);
        printf("Effective GID of owner	:%d\n", buf.shm_perm.gid);
	printf("Effective UID of creator:%d\n", buf.shm_perm.cuid);
	printf("Effective GID of creator:%d\n", buf.shm_perm.cgid);
	printf("Permissions + SHM_DEST and \
			SHM_LOCKED flags:%o\n", buf.shm_perm.mode);
	
	/* int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
/*	if((retshmctl = shmctl(shmid, SHM_INFO, &buf2)) < 0)
	{
		perror("shmctl");
		exit(1);
	}
	printf("return value of shmctl:%d\n", retshmctl);

	printf("******* printing system vide shminfo ********\n");

	printf("Maximum segment size		:%d\n", buf2.shmmax);
        printf("Minimum segment size always 1	:%ld\n", buf2.shmmin);
	printf("Maximum number of segments	:%ld\n", buf2.shmmni);
	printf("Maximum number of segments that a process can attach	:%ld\n", buf2.shmseg);
*/
	return 0;
}
