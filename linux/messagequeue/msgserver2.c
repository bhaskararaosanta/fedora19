#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<stdlib.h>

struct msgbuf{
	long int mtype;
	char mtext[30];
} msgsend = {100, "Hello bhaskar"}, msgrecv;

int main()
{
	int key, msgid, retmsgsnd, retmsgrcv;
	key = ftok(".", 'a');
	printf("value of IPC_CREAT:%d\n", IPC_CREAT);
	printf("value of IPC_EXCL:%d\n", IPC_EXCL);
	printf("value of IPC_PRIVATE:%d\n", IPC_PRIVATE);
	
	printf("return value of key:%d\n", key);
	
	/* msgget: int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgget:%d\n", msgid);

	/* msgsnd: int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgsend, sizeof(struct msgbuf), 0)) < 0)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);
	
	return 0;
}
