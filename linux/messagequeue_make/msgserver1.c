#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

struct msgbuf{
	long mtype;
	char mtext[50];
} msgserver = {1000, "Welcome to embedded system"};

int main()
{
	key_t key;
	int msgid, retmsgsnd;
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0)
	{
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("return value of key:%d\n", key);

	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message queue id:%d\n", msgid);

	/* int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct msgbuf), 0666)) < 0)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);

	printf("data items entering into the message queue as follows:\n");
//	msgserver.mtype = 1000;
//	strcpy(msgserver.mtext, "welcome to embedded system");
	printf("mtype entered in message queue is:%ld\n", msgserver.mtype);
	printf("mtext entered in message queue is:%s\n", msgserver.mtext);

	return 0;
}
