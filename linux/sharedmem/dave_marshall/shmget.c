/* Illustrate the shmget() system call. It prompts the arguments, makes the call and reports the result */

#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

extern void exit();
extern void perror();

int main()
{
	key_t key;
	int shmflg;
	int shmid;
	int size;

	(void)fprintf(stdout, "All numeric input is expected to follow C conventions:\n");
	(void)fprintf(stderr, "\t0x...is interpreted as hexadecimal,\n");
	(void)fprintf(stderr, "\t0...is interpreted as octal,\n");
	(void)fprintf(stderr, "\totherwise, decimal.\n");

	/* Get the key */
	(void)fprintf(stderr, "IPC_PRIVATE == %#lx\n", IPC_PRIVATE);
	(void)fprintf(stderr, "Enter Key:");
	(void)scanf("%li", &key);

	/* Get the size of shared memory segment */
	(void)fprintf(stderr, "Enter size:");
	(void)scanf("%i", &size);

	/* Get the shmglg value */
	(void)fprintf(stderr, "Expected flags for the shmflg argument are:\n");
	(void)fprintf(stderr, "\tIPC_CREAT = \t%#8.8o\n", IPC_CREAT);
	(void) fprintf(stderr, "\tIPC_EXCL = \t%#8.8o\n", IPC_EXCL);
	(void) fprintf(stderr, "\towner read =\t%#8.8o\n", 0400);
 	(void) fprintf(stderr, "\towner write =\t%#8.8o\n", 0200);
 	(void) fprintf(stderr, "\tgroup read =\t%#8.8o\n", 040);
 	(void) fprintf(stderr, "\tgroup write =\t%#8.8o\n", 020);
 	(void) fprintf(stderr, "\tother read =\t%#8.8o\n", 04);
 	(void) fprintf(stderr, "\tother write =\t%#8.8o\n", 02);
 	(void) fprintf(stderr, "Enter shmflg: ");
 	(void) scanf("%i", &shmflg);

 	/* Make the call and report the results. */
 	(void) fprintf(stderr, "shmget: Calling shmget(%#lx, %d, %#o)\n", key, size, shmflg);
 	if ((shmid = shmget (key, size, shmflg)) == -1) {
  		perror("shmget: shmget failed");
  		exit(1);
 	} else {
  		(void) fprintf(stderr, "shmget: shmget returned %d\n", shmid);
  		exit(0);
 	}
	return 0;
}

