#include<stdio.h>

void foo()
{
	int a = 10;
	static int sa = 10;

	a += 5;
	sa += 5;

	printf("Value of a:%d and sa:%d\n", a, sa);
}

int main()
{
	int i;
	for(i = 0; i < 10; i++)
	{
		foo();
	}
	return 0;
}
