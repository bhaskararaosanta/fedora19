#include<stdio.h>
int a = 100;
void f(void)
{
	a = 200;
}

int main()
{
	printf("a value in main function f():%d\n", a);
	f(); a;
	printf("a value in main function after f() call:%d\n", a);
	return 0;
}
