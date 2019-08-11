/* This program was taken from the following web link: http://osr600doc.xinuos.com/en/SDK_sysprog/_Example_Program8.html */

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<time.h>

static void do_shmctl();
extern void exit();
extern void perror();

int main()
{
	int uid, gid, mode;
	int rtrn, shmid, command, choice;
	struct shmid_ds shmid_ds, *buf; //shared memory data structure to hold result
	
	/* Get shmid and cmd */
	(void) fprintf(stderr, "Enter shmid for the desired segment:");
	(void) scanf("%i", &shmid);
	(void) fprintf(stderr, "valid shmctl cmd values are:\n");
	(void) fprintf(stderr, "\tIPC_RMID = \t%d\n", IPC_RMID);
	(void) fprintf(stderr, "\tIPC_SET = \t%d\n", IPC_SET);
	(void) fprintf(stderr, "\tIPC_STAT = \t%d\n", IPC_STAT);
	(void) fprintf(stderr, "\tSHM_LOCK = \t%d\n", SHM_LOCK);
	(void) fprintf(stderr, "\tSHM_UNLOCK = \t%d\n", SHM_UNLOCK);
	(void) fprintf(stderr, "Enter the desired cmd value:");
	(void) scanf("%i", &command);

	/* Check the values */
	printf("\nshmid = %d, command = %d\n", shmid, command);
	switch(command)
	{
		case IPC_STAT:
			/* use shmctl() to get the data structure for shmid in the
			 * shmid_ds area pointed to by buf and then print it outs. */
			rtrn = shmctl(shmid, IPC_STAT, buf);
			printf("The User ID = %d\n", buf->shm_perm.uid);
			printf("The Group ID = %d\n", buf->shm_perm.gid);
			printf("The Creator's ID = %d\n", buf->shm_perm.cuid);
			printf("The Creator's group ID = %d\n", buf->shm_perm.cgid);
			printf("The operation permissions = 0%o\n", buf->shm_perm.mode);
			printf("The slot usage sequence\n");
			//printf("number = 0%x\n", buf->shm_perm.seq);
			//printf("The key = 0%x\n", buf->shm_perm.key);
			printf("The segment size is = %d\n", buf->shm_segsz);
			printf("The PID of last shmop = %d\n", buf->shm_lpid);
			printf("The PID of creator = %d\n", buf->shm_cpid);
			printf("The current # attached = %d\n", buf->shm_nattch);
			printf("The last shmat time = %ld\n", buf->shm_atime);
			printf("The last shmdt time = %ld\n", buf->shm_dtime);
			printf("The last change time = %ld\n", buf->shm_ctime);
			break;
		case IPC_SET:
			/* Set owner UID and GID and permissions */
			/* Set UID, GID and permissions to be loaded */
			break;
		case IPC_RMID:
			/* Remove the segment when the last attach point is detached */
			break;
		case SHM_LOCK:
			/* Lock the shared memory segment */
			break;
		case SHM_UNLOCK:
			/* unlock the shared memory segment */
			break;
		default:
			/*unknown command will be passed to shmctl */
			break;
	}
	return 0;
}

