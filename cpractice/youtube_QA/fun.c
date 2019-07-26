#include<stdio.h>

void fun(int, int);

int main()
{
	int i = 5;
	fun(--i, i++);
	fun(++i, i--);
	printf("value of i in main:%d\n", i++);
	
	return 0;
}

void fun(int x, int y)
{
	printf("%d\t%d\n", x++, y--);
}
