#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} client;

int main()
{
	struct msqid_ds buf;
	int msgid, retmsgrcv, retmsgctl;
	key_t key;
	/* key_t ftok(const char *pathname, int proj_id); */
	if((key = ftok(".", 'a')) < 0) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	printf("key generated is:%d\n", key);

	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgid:%d\n", msgid);

	/* ssize_t msgrcv(int msgid, void *msgp, size_t msgsz, long mtype, int msgflg); */
	if((retmsgrcv = msgrcv(msgid, &client, sizeof(struct msgbuf), 100, 0666)) < 0) {
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv:%d\n", retmsgrcv);

	printf("messgae received through message queue is:%s\n", client.mtext);

	/* int msgctl(int msgid, int cmd, struct msqid_ds *buf); */
	if((retmsgctl = msgctl(msgid, IPC_STAT, &buf)) < 0) {
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl:%d\n", retmsgctl);

	printf("********* printing message queue stats **********\n");

	printf("Time of last msgsnd(2)		:%s\n", ctime(&buf. msg_stime));
        printf("Time of last msgrcv(2)		:%s\n", ctime(&buf.msg_rtime));
        printf("Time of last change		:%s\n", ctime(&buf.msg_ctime));
        printf("Current number of bytes in queue (nonstandard)	:%ld\n", buf.__msg_cbytes);
        printf("Current number of messages in queue		:%d\n", buf.msg_qnum);
        printf("Maximum number of bytes allowed in queue	:%d\n", buf.msg_qbytes);
	printf("PID of last msgsnd(2)		:%d\n", buf.msg_lspid);
	printf("PID of last msgrcv(2)		:%d\n", buf.msg_lrpid);
	printf("Key supplied to msgget(2)	:%d\n", buf.msg_perm.__key);
	printf("Effective UID of owner		:%d\n", buf.msg_perm.uid);
        printf("Effective GID of owner		:%d\n", buf.msg_perm.gid);
        printf("Effective UID of creator	:%d\n", buf.msg_perm.cuid);
	printf("Effective GID of creator	:%d\n", buf.msg_perm.cgid);
	printf("Permissions			:%o\n", buf.msg_perm.mode);
	printf("Sequence number			:%d\n", buf.msg_perm.__seq);

	printf("********** End of printing stats **************\n");

	return 0;
}


