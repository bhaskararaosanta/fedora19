#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>

//#define	SHMSIZE	27
struct shmshare {
	int data;
	char name[30];
};

int main()
{
	struct shmid_ds buf;
	struct shmshare *shmbuffer;
	int i, shmid, retshmctl, retshmdt;
	key_t key;
	char *retaddr;
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("key value:%d\n", key);

	/* int shmget(key_t key, size_t size, int shmflg); */
	//if((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0) {
	if((shmid = shmget(key, sizeof(struct shmshare), IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(EXIT_FAILURE);
	}
	printf("Return value of shmid:%d\n", shmid);

	/* void *shmat(int shmid, const void *shmaddr, int shmflg); */
	//if((retaddr = shmat(shmid, NULL, 0666)) == (char *)-1) {
	if((shmbuffer = (struct shmshare *)shmat(shmid, NULL, 0666)) == (struct shmshare *)-1) {
		perror("shmat");
		exit(EXIT_FAILURE);
	}
	printf("memory location where segment attached:%p\n", shmbuffer);

	/*for(i = 1; i <= 26; i++) {
		printf("data available in shared memory:%c\t", *retaddr);
		retaddr++;
	}*/

	printf("integer stored in segment:%d\n", shmbuffer->data);
	printf("char string stored in segment:%s\n", shmbuffer->name);

	/* int shmctl(int shmid, int cmd, struct shmid_ds *buf); */
	if((retshmctl = shmctl(shmid, IPC_STAT, &buf)) < 0) {
		perror("shmctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmctl:%d\n", retshmctl);

	printf("****** printing shm statistics *********\n");
	printf("size of segment size in bytes	:%d\n", buf.shm_segsz);
	printf("Last attach time	:%s\n", ctime(&buf.shm_atime));
	printf("Last detach time	:%s\n", ctime(&buf.shm_dtime));
	printf("Last change time	:%s\n", ctime(&buf.shm_ctime));
	printf("PID of creator		:%d\n", buf.shm_cpid);
	printf("PID of last shmat	:%d\n", buf.shm_lpid);
	printf("No. of currrent attach	:%d\n", buf.shm_nattch);
	printf("Key supplied to shmget	:%d\n", buf.shm_perm.__key);
	printf("Effective UID of owner	:%d\n", buf.shm_perm.uid);
	printf("Effective GID of owner	:%d\n", buf.shm_perm.gid);
	printf("Effective UID of creator:%d\n", buf.shm_perm.cuid);
	printf("Effective GID of creator:%d\n", buf.shm_perm.cgid);
	printf("Permissions + flags	:%o\n", buf.shm_perm.mode);
	printf("****** End of printing shm statistics *********\n");

	/* int shmdt(const void *shmaddr); */
	if((retshmdt = shmdt(shmbuffer)) < 0) {
		perror("shmdt");
		exit(EXIT_FAILURE);
	}
	printf("return value of shmdt:%d\n", retshmdt);

	return 0;
}
