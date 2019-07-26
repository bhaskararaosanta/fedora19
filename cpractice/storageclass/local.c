#include<stdio.h>

void f(void)
{
	int a = 10;
	printf("a value in function f():%d\n", a);
}

int main()
{
	f();
	f();
	f();
	return 0;
}
