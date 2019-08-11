#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf{
	long mtype;
	char mtext[30];
} msgsend = {100, "Hello, bhaskar"};

int main()
{
	int msgid, retmsgsnd, retmsgrcv;

	key_t key = ftok(".", 'a');
	printf("return value of key:%d\n", (int)key);

	/* int msgget(key_ key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgget or message queue id:%d\n", msgid);

	if((retmsgsnd = msgsnd(msgid, &msgsend, sizeof(struct msgbuf), 0666)) < 0)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd is:%d\n", retmsgsnd);

	return 0;
}
