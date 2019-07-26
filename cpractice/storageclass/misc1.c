#include<stdio.h>
int a = 10;
void f(void)
{
	int a = 71;
	printf("a value in fun f():%d\n", a++);
}

int main()
{
	int a = 17;
	printf("a value in main function f():%d\n", a++);
	f();
	printf("a value in main function after f() call:%d\n", a++);
	f();
	printf("a value in main function second f() call:%d\n", a++);
	f();
	return 0;
}
