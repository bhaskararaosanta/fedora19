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

	/* msgrcv: ssize_t msgrcv(int msgid, void *msgp, size_t msgsz, long mtype, int msgflg); */
	if((retmsgrcv = msgrcv(msgid, &msgrecv, sizeof(struct msgbuf), 100, 0)) < 0)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv:%d\n", retmsgrcv);
	printf("message received through message queue:%s\n", msgrecv.mtext);
	
	return 0;
}
