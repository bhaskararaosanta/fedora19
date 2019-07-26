#include<stdio.h>

int i = 30;
int main()
{
	extern int i;
	/* i = 20;  we can't define the identifier in the scope of extern variable */
	printf("%d\n", i);
	return 0;
}
