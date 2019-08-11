#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>

struct msgbuf{
	long int mtype;
	char mtext[20];
} msg_snd = {100, "Hello Bhaskar"}, msg_rcv;

int main()
{
	key_t key = ftok(".", 'a');
	int msgid, retmsgsnd;
	printf("Value of key is:%d\n", key);

	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Value of message queue id:%d\n", msgid);

	if((retmsgsnd = msgsnd(msgid, &msg_snd, sizeof(struct msgbuf), 0666)) < 0)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("Return value of msgsnd is: %d\n", retmsgsnd);

	return 0;
}
	


