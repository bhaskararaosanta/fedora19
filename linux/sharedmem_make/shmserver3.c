#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

//#define	SHMSIZE	27
struct shmshare {
	int data;
	char name[30];
};

int main()
{
	struct shmshare *shmbuffer;
	int i, shmid;
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
	if((shmid = shmget(key, (int)sizeof(struct shmshare), IPC_CREAT | 0666)) < 0) {
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

	/*for(i = 'a'; i <= 'z'; i++) {
		*retaddr = i;
		retaddr++;
	}*/

	shmbuffer->data = 5000;
	strcpy(shmbuffer->name, "Emedded is great");

	return 0;
}
