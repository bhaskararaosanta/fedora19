#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

struct msgbuf{
	long mtype;
	char mtext[30];
}send = {100, "Bhaskar is a good boy"}, recv;

int main()
{
	int msgid, retmsgsnd;
	key_t key = ftok(".", 'a');
	printf("Value of IPC_CREAT:%o\n", IPC_CREAT);
	printf("Value of IPC_EXCL:%o\n", IPC_EXCL);
	printf("Value of IPC_PRIVATE:%o\n", IPC_PRIVATE);
	printf("*************************\n");
	printf("Value of key:%d\n", key);

	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Value of msgid:%d\n", msgid);

	if((retmsgsnd = msgsnd(msgid, (void *)&send, sizeof(struct msgbuf), 0666)) == -1)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}

	return 0;
}

