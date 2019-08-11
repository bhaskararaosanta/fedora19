#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf{
	long mtype;
	char mtext[30];
} msgrecv;

int main()
{
	int msgid, retmsgsnd, retmsgrcv;

	key_t key = ftok(".", 'a');
	printf("return value of key:%d\n", (int)key);

	/* int msgget(key_ key, int msgflg); */
	if((msgid = msgget(key, 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgget or message queue id:%d\n", msgid);

	if((retmsgrcv = msgrcv(msgid, &msgrecv, sizeof(struct msgbuf), 100, 0666)) < 0)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv is:%d\n", retmsgrcv);

	printf("Data received from message queue:%s\n", msgrecv.mtext);

	return 0;
}
