#include<stdio.h>
#include<stdlib.h>

#define INTEL 100

int main()
{

	#ifdef INTEL
		printf("INTEL macro is already defined:%d\n", INTEL);
	#endif

	#ifndef INTEL
		printf("INTEL macro is not defined:\n");
	#else
		printf("Nothing great:\n");
	#endif

	return 0;
}
