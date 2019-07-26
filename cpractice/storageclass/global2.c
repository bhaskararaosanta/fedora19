#include<stdio.h>

int a = 10;

void fun(void)
{
	printf("value of 'a' in function fun:%d\n", a++);
}

int main()
{
	fun();
	a++;
	fun();
	a++;
	fun();
	a++;

	return 0;
}
