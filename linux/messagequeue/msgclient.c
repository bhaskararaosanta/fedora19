#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<time.h>

struct msgbuf{
	long mtype;
	char mtext[30];
} recv, recv1;

int main()
{
	struct msqid_ds buf;
	int msgid, retmsgrcv, retmsgctl;
	key_t key = ftok(".", 'a');
	printf("Value of IPC_SET:%o\n", IPC_SET);
	printf("Value of IPC_STAT:%o\n", IPC_STAT);
	printf("Value of IPC_RMID:%o\n", IPC_RMID);
	printf("Value of IPC_CREAT:%o\n", IPC_CREAT);
	printf("Value of IPC_EXCL:%o\n", IPC_EXCL);
	printf("Value of IPC_PRIVATE:%o\n", IPC_PRIVATE);
	printf("*************************\n");
	printf("Value of key:%d\n", key);

	if((msgid = msgget(key, 0666)) < 0)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Value of msgid:%d\n", msgid);

	if((retmsgrcv = msgrcv(msgid, (void *)&recv, sizeof(struct msgbuf), 100, 0666)) == -1)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}

	if((retmsgrcv = msgrcv(msgid, (void *)&recv1, sizeof(struct msgbuf), 500, 0666)) == -1)
	{
		perror("msgrcv");
		exit(EXIT_FAILURE);
	}
	printf("Data received from message queue with mtype 100 is:%s\n", recv.mtext);
	printf("Data received from message queue with mtype 500 is:%s\n", recv1.mtext);

	if((retmsgctl = msgctl(msgid, IPC_STAT, &buf)) < 0)
	{
		perror("msgctl");
		exit(EXIT_FAILURE);
	}
	printf("Return value of msgctl:%d\n", retmsgctl);

	printf("The User ID = %d\n", buf.msg_perm.uid);
        printf("The Group ID = %d\n", buf.msg_perm.gid);
        printf("The Creator's ID = %d\n", buf.msg_perm.cuid);
        printf("The Creator's group ID = %d\n", buf.msg_perm.cgid);
        printf("The operation permissions = 0%o\n", buf.msg_perm.mode);
        printf("The slot usage sequence\n");
     	printf("number = 0%x\n", buf.msg_perm.__seq);
        printf("The PID of last message send = %d\n", buf.msg_lspid);
        printf("The PID of last message recv = %d\n", buf.msg_lrpid);
/*        printf("The last send time = %ld\n", ctime(buf.msg_stime));
        printf("The last recv time = %ld\n", ctime(buf.msg_rtime));
        printf("The last change time = %ld\n", ctime(buf.msg_ctime)); */
	
	return 0;
}

