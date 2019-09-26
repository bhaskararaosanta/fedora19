#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <string.h>
#include <stdlib.h>

struct semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

int main()
{
	struct semun u;
	u.val = 1;
	key_t key;
	pid_t cpid;
	int semid, retsemctl, retsemop;

	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0)
	{
		perror("ftok");
		exit(1);
	}
	printf("return value of key:%d\n", key);

	/* int semget(key_t key, int nsems, int semflg); */
	if((semid = semget(key, 1, IPC_CREAT | 0666)) < 0)
	{
		perror("semget");
		exit(1);
	}
	printf("return value of semid:%d\n", semid);
	
	/* int semctl(int semid, int semnum, int cmd, ...); */
	if((retsemctl = semctl(semid, 0, SETVAL, u)) < 0)
	{
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	printf("Return value of semctl:%d\n", retsemctl);
	
	/* pid_t fork(void); */
	if((cpid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}

	else if(cpid == 0)
	{
		char *s = "abcdefghijkl";
		int len = strlen(s);
		
		for(int i = 0; i < len; i++)
		{
			/* ins semopint semid, struct sembud *sops, size_t nsops); */
			if((retsemop = semop(semid, &p, 1)) < 0)
			{
				perror("semop p");
				exit(1);
			}
			//printf("return value of semop p:%d\n", retsemop);
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			/* ins semopint semid, struct sembud *sops, size_t nsops); */
			if((retsemop = semop(semid, &v, 1)) < 0)
			{
				perror("semop p");
				exit(1);
			}
			//printf("return value of semop p:%d\n", retsemop);
		}
	}
	
	else
	{
		char *s = "ABCDEFGHIJKL";
		int len = strlen(s);

		for(int i = 0; i < len; i++)
		{
			/* ins semopint semid, struct sembud *sops, size_t nsops); */
			if((retsemop = semop(semid, &p, 1)) < 0)
			{
				perror("semop p");
				exit(1);
			}
			//printf("return value of semop p:%d\n", retsemop);
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			/* ins semopint semid, struct sembud *sops, size_t nsops); */
			if((retsemop = semop(semid, &v, 1)) < 0)
			{
				perror("semop v");
				exit(1);
			}
			//printf("return value of semop p:%d\n", retsemop);
		}
	}

	return 0;
}

