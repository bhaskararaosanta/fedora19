#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>

struct msgbuf{
	long mtype;
	char mtext[50];
} msgclient;

int main()
{
	struct msqid_ds buffer;
	key_t key;
	int msgid, retmsgrcv, retmsgctl;
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

	/* int msgrcv(int msgid, const void *msgp, size_t msgsz, long mtype, int msgflg); */
	if((retmsgrcv = msgrcv(msgid, &msgclient, sizeof(struct msgbuf), 1000, 0666)) < 0)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv:%d\n", retmsgrcv);

	printf("data items reading from the message queue as follows:\n");
	
	printf("mtype value available in message queue is:%ld\n", msgclient.mtype);
	printf("mtext data available in message queue is:%s\n", msgclient.mtext);
	
	/* int msgctl(int msgid, int cmd, struct msqid_ds *buf); */
	if((retmsgctl = msgctl(msgid, IPC_STAT, &buffer)) < 0)
	{
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl:%d\n", retmsgctl);

	printf("Values printing from message queye kernel structure as follows:\n");
	
	printf("Time of Last msgsnd:%s\n", ctime(&buffer.msg_stime));
        printf("Time of Last msgrcv:%s\n", ctime(&buffer.msg_rtime));
        printf("Time of Last change:%s\n", ctime(&buffer.msg_ctime));
	printf("Current number of bytes in queue (nonstandard):%d\n", buffer.__msg_cbytes);
	printf("Current number of messages in queue:%d\n", buffer.msg_qbytes);
        printf("PID of last msgsnd():%d\n", buffer.msg_lspid);
        printf("PID of last msgrcv():%d\n", buffer.msg_lrpid);

	printf("Key supplied to msgget(2):%d\n", buffer.msg_perm.__key);
        printf("Effective UID of owner:%d\n", buffer.msg_perm.uid);
        printf("Effective GID of owner:%d\n", buffer.msg_perm.gid);
	printf("Effective UID of creator:%d\n", buffer.msg_perm.cuid);
        printf("Effective GID of creator:%d\n", buffer.msg_perm.cgid);
        printf("Permissions:%o\n", buffer.msg_perm.mode);
        printf("Sequence number:%d\n", buffer.msg_perm.__seq);

	return 0;

	return 0;
}
