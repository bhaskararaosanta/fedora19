#include<stdio.h>

int main()
{
	int *ptr = (int *)0x8388538;
	*ptr = 50;
	printf("value stored at memory location 0x8388538 is:%d\t%d\n", *ptr, (int *)0x8388538);

	return 0;
}
