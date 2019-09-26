#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} msgserver = {100, "Welcome to Embedded world"};

int main()
{
	struct msqid_ds buf;

	/* key_t key(const char *pathname, int proj_id); */
	key_t key = ftok(".", 'a');
	printf("return value of ftok or key value:%d\n", key);
	
	int msgid, retmsgsnd, retmsgctl;

	/* int msgget(key_t key, int msgflg); */
	if((msgid = msgget(key, IPC_CREAT | 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("msg queue id:%d\n", msgid);

	/* int msgsnd(int msgid, const void *msgp, size_t msgsz, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct msgbuf), 0)) < 0)
	{
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);

	printf("message send to queue is:%s\n", msgserver.mtext);

	/* int msgctl(int msgid, int cmd, struct msqid_ds *buf); */
	if((retmsgctl = msgctl(msgid, IPC_STAT, &buf)) < 0)
	{
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgctl:%d\n", retmsgctl);
	
	printf("********* printing message queue statistics **********\n");

	printf("Time of last msgsnd(2) 		:%s\n", ctime(&buf.msg_stime));
        printf("Time of last msgrcv(2) 		:%s\n", ctime(&buf.msg_rtime));
        printf("Time of last change 		:%s\n", ctime(&buf.msg_ctime));
        printf("Current number of bytes in queue (nonstandard):%d\n", buf.__msg_cbytes);
        printf("Current number of messages in queue	:%d\n", buf.msg_qnum);
        printf("Maximum number of bytes allowed in queue	:%d\n", buf.msg_qbytes);
        printf("PID of last msgsnd(2)		:%d\n", buf.msg_lspid);
        printf("PID of last msgrcv(2)		:%d\n", buf.msg_lrpid);
        printf("****** struct ipc_perm values ********\n");
        printf("Key supplied to msgget(2)	:%d\n", buf.msg_perm.__key);
        printf("Effective UID of owner		:%d\n", buf.msg_perm.uid);	
        printf("Effective GID of owner	 	:%d\n", buf.msg_perm.gid);
        printf("Effective UID of creator 	:%d\n", buf.msg_perm.cuid);
        printf("Effective GID of creator	:%d\n", buf.msg_perm.cgid);
        printf("Permissions			:%o\n", buf.msg_perm.mode);
	printf("Sequence number			:%d\n", buf.msg_perm.__seq);


       return 0;
}
