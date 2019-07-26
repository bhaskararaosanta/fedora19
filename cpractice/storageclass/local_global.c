#include<stdio.h>

int a = 100;

void fun(void)
{
	//a = 10;
	int a = 10; /* adding data type here will have different results */
	printf("value of 'a' in function fun:%d\n", a++);
}

int main()
{
	//int a = 10000;
	a = 10000;	/* there is no difference here including data type here */
	printf("value of 'a' in main:%d\n", a);
	fun();
	printf("value of 'a' in main:%d\n", a);
	fun();
	return 0;
}
