#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} server = {100, "Embedded is great"};

int main()
{
	struct msqid_ds buf;
	int msgid, retmsgsnd, retmsgctl;
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

	/* int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &server, sizeof(struct msgbuf), 0666)) < 0) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);

	printf("messgae attached through message queue is:%s\n", server.mtext);

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


