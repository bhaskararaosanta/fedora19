#include<stdio.h>

#define	BHASKAR	100

#define	DEEPAK

int main()
{
	#ifdef	BHASKAR
		printf("BHASKAR is already defined:%d\n", BHASKAR);
	#undef DEEPAK
	#endif

	#ifndef	DEEPAK
		printf("DEEPAK is not defined:\n");
	#else
		printf("Then define DEEPAK:\n");
	#endif

	return 0;
}

