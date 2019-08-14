#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

union semun{
	int val;		/* Value for SETVAL */
	struct semid_ds *buf;	/* Buffer for IPC_STAT and IPC_SET */
	unsigned short *array;	/* Array for GETALL and SETALL */
	struct seminfo *__buf;	/* Buffer for IPC_INFO */
};

int main()
{
	
	key_t key = ftok(".", 'a');
	printf("return value of key:%d\n", (int)key);
	int semid, retsemctl, retsemop;
	pid_t pid;
	struct sembuf p = {0, -1, SEM_UNDO};
	struct sembuf v = {0, +1, SEM_UNDO};
	union semun u;
	u.val = 1;

	/* int semget(key_t key, int nsems, int semflg); */
	if((semid = semget(key, 1, IPC_CREAT | 0666)) < 0)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}
	printf("return value of semget or semaphore id:%d\n", semid);

	/* int semctl(semid, int semnum, int cmd, ...); */
	if((retsemctl = semctl(semid, 0, SETVAL, u)) < 0)
	{
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of semctl:%d\n", retsemctl);

	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		char *s = "abcdefghijkl";
		int l = strlen(s);
		for(int i = 0; i < l; i++)
		{
			/* int semop(semid, struct sembuf *sops, size_t nsops); */
			if((retsemop = semop(semid, &p, 1)) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			//printf("return value of retsemop:%d\n", retsemop);
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			putchar(s[i]);
			fflush(stdout);
			/* int semop(semid, struct sembuf *sops, size_t nsops); */
			if((retsemop = semop(semid, &v, 1)) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(1);
		}
	}
	else
	{
		char *s = "ABCDEFGHIJKL";
		int l = strlen(s);
		for(int i = 0; i < l; i++)
		{
			/* int semop(semid, struct sembuf *sops, size_t nsops); */
			if((retsemop = semop(semid, &p, 1)) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			//printf("return value of retsemop:%d\n", retsemop);
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			putchar(s[i]);
			fflush(stdout);
			/* int semop(semid, struct sembuf *sops, size_t nsops); */
			if((retsemop = semop(semid, &v, 1)) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(1);
		}
	}
	
	return 0;
}



