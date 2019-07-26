#include<stdio.h>

int a = 100;

void fun(void)
{
	a = 110;
	int a = 10; /* adding data type here will have different results */
	printf("value of 'a' in function fun:%d\n", a++);
}

int main()
{
//	int a = 10000;
	printf("value of 'a' in main:%d\n", a++);
	{
		int a = 10000000;
		printf("value of 'a' inside another block in main:%d\n", a);
	}
	fun();
	printf("value of 'a' in main:%d\n", a++);
	fun();
	return 0;
}
