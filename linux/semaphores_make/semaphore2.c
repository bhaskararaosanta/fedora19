#include <stdio.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
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

	if((semid = semget(key, 1, IPC_CREAT | 0666)) < 0)
	{
		perror("semget");
		exit(EXIT_FAILURE);
	}
	printf("Semaphore ID value:%d\n", semid);

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
			if((retsemop = semop(semid, &p, 1)) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			putchar(s[i]);
			fflush(stdout);
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
			if((retsemop = semop(semid, &p, 1)) < 0)
			{
				perror("semop p");
				exit(EXIT_FAILURE);
			}
			putchar(s[i]);
			fflush(stdout);
			sleep(1);
			putchar(s[i]);
			fflush(stdout);
			if((retsemop = semop(semid, &v, 1)) < 0)
			{
				perror("semop v");
				exit(EXIT_FAILURE);
			}
			sleep(1);
		}
	printf("\n");
	}

	return 0;
}



