#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define	KEY	0x1111

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
};
struct sembuf p = {0, -1, SEM_UNDO};
struct sembuf v = {0, +1, SEM_UNDO};

int main()
{
	int semid = semget(KEY, 1, IPC_CREAT | 0666);
	if(semid < 0)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}
	union semun u;
	u.val = 1;
	if(semctl(semid, 0, SETVAL, u) < 0)
	{
		perror("semctl");
		exit(EXIT_FAILURE);
	}

	int pid;
	pid = fork();
	//srand(pid);
	if(pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if(pid)
	{
		char *s = "abcdefgh";
		int i, l = strlen(s);
		for(i = 0; i < l; i++)
		{
			if(semop(semid, &p, 1) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			//sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(semid, &v, 1) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			//sleep(rand() % 2);
		}
	}
	else
	{
		char *s = "ABCDEFGH";
		int i, l = strlen(s);
		for(i = 0; i < l; i++)
		{
			if(semop(semid, &p, 1) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			//sleep(rand() % 2);
			putchar(s[i]);
			fflush(stdout);
			if(semop(semid, &v, 1) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			//sleep(rand() % 2);
		}
	}
	
	return 0;
}
