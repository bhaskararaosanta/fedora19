#include<stdio.h>

int main()
{
	extern int out;
	/* i = 20;  we can't define the identifier in the scope of extern variable */
	printf("%d\n", out);
	return 0;
}
int out = 500;
