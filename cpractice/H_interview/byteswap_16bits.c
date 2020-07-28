#include <stdio.h>
#include <stddef.h>

#define	BYTESWAP_16(x)	\
	(((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))

int main()
{
	printf("%x\n", 0xf25a);
	printf("The hexadecimal 0xf25a bytes will be swapped\n");
	printf("%x\n", BYTESWAP_16(0xf25a));

	return 0;
}
