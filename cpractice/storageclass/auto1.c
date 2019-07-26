#include<stdio.h>

void fun(void)
{
	int a = 10;
	printf("value of 'a' in function fun:%d\n", a++);
}

int main()
{
	fun();
	fun();
	fun();

	return 0;
}
