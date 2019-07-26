#include<stdio.h>

int main()
{
	int *ptr;
	ptr = (int *)0x40000000;
	*ptr = 100;
	return 0;
}
