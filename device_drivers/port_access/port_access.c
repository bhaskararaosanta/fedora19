/* very simple example of port I/O
 * This code nothing useful, just a port write, a sleep,
 * ad a port read. Compile with 'gcc -O2 -o port_access port_access.c',
 * and run as root with './port_access'. */

#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>
#include <stdlib.h>

#define	BASEPORT 0x378	/*lp1 */

int main()
{
	/* get access to the ports */
	/* int ioperm(unsigned long from, unsigned long num, int turn_on); */
	if(ioperm(BASEPORT, 3, 1)) {
		perror("ioperm");
		exit(EXIT_FAILURE);
	}

	/* Set the data signals D0 to D7 of the port to all low (0) */
	/* void outb(unsigned char value, unsigned short int port); */
	outb(0xFF, BASEPORT);

	/* sleep for a while let say100ms */
	usleep(100000);

	/* Read from the status port (BASE + 1) and display the result  */
	/* unsigned char inb(unsigned short int port); */
	printf("status %d\n", inb(BASEPORT + 0));
	printf("status %d\n", inb(BASEPORT + 1));
	printf("status %d\n", inb(BASEPORT + 2));

	/* We have to releae the ports from rhis process */
	if(ioperm(BASEPORT, 3, 9)) {
		perror("ioperm");
		exit(EXIT_FAILURE);
	}

	return 0;
}
