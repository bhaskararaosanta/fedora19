#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} msgclient;

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
	printf("key value:%d\n", key);

	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
	       perror("msgget");
       		exit(EXIT_FAILURE);
	}
	printf("value of msgid:%d\n", msgid);
	
	/* ssize_t msgrcv(int msgid, void *msgp, size_t size, long mtype, int msgflg); */
	if((retmsgrcv = msgrcv(msgid, &msgclient, sizeof(struct msgbuf), 100, 0666)) < 0) {
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgrcv:%d\n", retmsgrcv);
	printf("Message mtype received to queue:%d\n", msgclient.mtype);
	printf("Message mtext reeived to queue:%s\n", msgclient.mtext);

	/* int msgctl(int msgid, int cmd, struct msqid_ds *buf); */
	if((retmsgctl = msgctl(msgid, IPC_STAT, &buf)) < 0) {
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl:%d\n", retmsgctl);

	printf("****** msg queue statistics *******\n");
	printf("Time of last msgsnd()	:%s\n", ctime(&buf.msg_stime));
	printf("Time of last msgrcv()	:%s\n", ctime(&buf.msg_rtime));
	printf("Time of last change	:%s\n", ctime(&buf.msg_ctime));
	printf("no. of bytes in queue	:%ld\n", buf.__msg_cbytes);
	printf("no. of msgs in queue	:%d\n", buf.msg_qnum);
	printf("max bytes allowed in que:%d\n", buf.msg_qbytes);
	printf("PID of last msgsnd()	:%d\n", buf.msg_lspid);
	printf("PID of last msgrcv()	:%d\n", buf.msg_lrpid);
	printf("key supplied to msgget():%d\n", buf.msg_perm.__key);
	printf("Effectibe UID of owner	:%d\n", buf.msg_perm.uid);
	printf("Effectibe GID of owner	:%d\n", buf.msg_perm.gid);
	printf("Effectibe UID of creator:%d\n", buf.msg_perm.cuid);
	printf("Effectibe GID of creator:%d\n", buf.msg_perm.cgid);
	printf("Permissions		:%o\n", buf.msg_perm.mode);
	printf("Sequence number		:%d\n", buf.msg_perm.__seq);
	printf("******** End of stats ************\n");

	return 0;
}


