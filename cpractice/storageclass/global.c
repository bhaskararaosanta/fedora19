#include<stdio.h>
int a = 10;
//static int a = 20;
void f(void)
{
	//int a = 100;
	//static int a = 200;
	printf("a value in function f():%d\n", a++);
}

int main()
{
	f();
	f();
	f();

	return 0;
}
