#include <stdio.h>

int main()
{
	int i = 10, j = 20;
	int sub;

	asm
	{
		mov eax, i
		sub eax, j
		mov sub eax
	}

	printf("sub value is:%d\n", sub;

	return 0;
}
