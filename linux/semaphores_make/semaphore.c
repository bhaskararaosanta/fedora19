#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};

struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

int main()
{
	key_t key = ftok(".", 'a');
	int semid, retsemctl;
	printf("Value of key:%d\n", (int)key);

	/* int semget(key_t key, int nsems, int semflg); */
	if((semid = semget(key, 1, IPC_CREAT | 0666)) < 0)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}
	printf("Return value of semget or semaphore set identifier:%d\n", semid);

	printf("Size of union semun is:%d\n", sizeof(union semun));

	union semun u;
	u.val = 1;
	if((retsemctl = semctl(semid, 0, SETVAL, u)) < 0)
	{
		perror("semctl");
		exit(EXIT_FAILURE);
	}
	printf("Return value of semctl:%d\n", retsemctl);

	int pid;
	if((pid = fork()) < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		char *s = "abcdefgh";
		int l = strlen(s);
		for(int i = 0; i < l; i++)
		{
			if(semop(semid, &p, 1) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(semid, &v, 1) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(2);
		}
	}

	else
	{
		char *s = "ABCDEFGH";
		int l = strlen(s);
		for(int i = 0; i < l; i++)
		{
			if(semop(semid, &p, 1) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(semid, &v, 1) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(2);
		}
	}

	return 0;
}



