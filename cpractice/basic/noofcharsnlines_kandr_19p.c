#include<stdio.h>

int main()
{
	int nl =0, nc = 0;
	char c;

	while((c = getchar()) != EOF)  /* EOF is equal to -1 and same can be used in program */
	{	
		if(c == '\n')
			++nl;
		++nc;
	}

	printf("no. of characters read is:%d\nno. of lines read is:%d\n", nc, nl);

	return 0;
}
