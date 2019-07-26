#include<stdio.h>

int main()
{
	char *p;
	printf("%d\t%d\n", sizeof(*p), sizeof(p));

	return 0;
}
