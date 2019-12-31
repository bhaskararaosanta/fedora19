#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

struct message {
	long int mtype;
	char mtext[30];
} msgserver = {100, "Embedded is good"};

int main()
{
	struct msqid_ds mybuf;
	int i, msgid, retmsgsnd, retmsgctl;
	
	/* key_t ftok(const char *pathname, int proj_id); */
	key_t key = ftok(".", 'a');
	printf("Key value is:%d\n", (int) key);
	
	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Return value of msgid:%d\n",msgid);
	
	for(i = 0; i < 10; i++) {
		sleep(2);
	/* int msgsnd(int msgid, cost void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct message), 0)) < 0) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);
	printf("messgae send through message queue:%s\n", msgserver.mtext);
	printf("message id send through message queue:%d\n", msgserver.mtype);
	
	/* int msgctl(int msgid, int cmd,struct msqid_ds *buf); */
	if((retmsgctl = msgctl(msgid, IPC_STAT, &mybuf)) < 0) {
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl:%d\n", retmsgctl);
	printf("************** message queue stats ***************\n");
	
	printf("ownership and permissions	:\n");
	printf("key supplied to msgget(2)	:%d\n", mybuf.msg_perm.__key);
	printf("Effective UID of owner		:%d\n", mybuf.msg_perm.uid);	
	printf("Effective GID of owner		:%d\n", mybuf.msg_perm.gid);	
	printf("Effective UID of creator	:%d\n", mybuf.msg_perm.cuid);	
	printf("Effective GID of creator	:%d\n", mybuf.msg_perm.cgid);
	printf("Permissions			:%o\n", mybuf.msg_perm.mode);
	printf("Sequence number			:%d\n", mybuf.msg_perm.__seq);

	printf("Time of last msgsnd(2)		:%s\n", ctime(&mybuf.msg_stime));	
	printf("Time of last msgrcv(2)		:%s\n", ctime(&mybuf.msg_rtime));	
	printf("Time of last change		:%s\n", ctime(&mybuf.msg_ctime));	
	printf("Time of last msgsnd(2)		:%s\n", ctime(&mybuf.msg_stime));	
	printf("number of bytes in queue	:%d\n", mybuf.__msg_cbytes);
	printf("number of messages in queue	:%d\n", mybuf.msg_qnum);
	printf("max no. of bytes allowed in que	:%d\n", mybuf.msg_qbytes);
	printf("PID of last msgsnd(2)		:%d\n", mybuf.msg_lspid);
	printf("PID of last msgcv(2)		:%d\n", mybuf.msg_lrpid);

	printf("******* end of message queue stats ****************\n");

	return 0;
}


