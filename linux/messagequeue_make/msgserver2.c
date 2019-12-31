#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct msgbuf {
	long mtype;
	char mtext[30];
} msgserver = {100, "Embedded is great"};

int main()
{
	struct msqid_ds buf;
	int msgid, retmsgsnd;
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
	
	/* int msgsnd(int msgid, const void *msgp, size_t size, int msgflg); */
	if((retmsgsnd = msgsnd(msgid, &msgserver, sizeof(struct msgbuf), 0666)) < 0) {
		perror("msgsnd");
		exit(EXIT_FAILURE);
	}
	printf("return value of msgsnd:%d\n", retmsgsnd);
	printf("Message mtype send to queue:%d\n", msgserver.mtype);
	printf("Message mtext send to queue:%s\n", msgserver.mtext);

	return 0;
}


