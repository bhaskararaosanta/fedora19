/* This is taken from askubuntu forum
 * https://askubuntu.com/questions/22100/usage-of-inb-inl-inw-to-access-kernel-space-from-user-space
 * 
 * And the program shall be compiled using gcc optimization like gcc -O filename.c */

#include <stdio.h>
#include <unistd.h>
#include <sys/io.h>

int main()
{
	unsigned char orig, bits;

	/* gain access to speaker control port */
	if (ioperm(0x61, 0x61, 1) < 0) {
	perror("0x61");
	return 1;
	}
	/* gain access to speaker frequency port */
	if (ioperm(0x42, 0x42, 1) < 0) {
	perror("0x42");
	return 2;
	}

	/* turn on speaker */
	orig = bits = inb(0x61);
	bits |= 3;
	outb(bits, 0x61);

	/* set 1000 Hz frequency */
	bits = 0xA9;
	outb(bits, 0x42);
	bits = 0x04;
	outb(bits, 0x42);
	
	/* listen to the beep */
	sleep(10);

	/* restore speaker bits to turn off speaker */
	outb(orig, 0x61);

	return 0;
}
