#include<stdio.h>

int main()
{
	int nc = 0;
	char c;

	while((c = getchar()) != EOF)  /* EOF is equal to -1 and same can be used in program */
		++nc;

	printf("no. of characters read is:%d\n", nc);

	return 0;
}
