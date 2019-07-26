#include<stdio.h>
int a = 100;
void f(void)
{
	printf("a value in function f():%d\n", a++);
}

int main()
{
	//int a = 200;
	f(); a++;
	printf("a value in function f():%d\n", a++);
	f(); a++;
	printf("a value in function f():%d\n", a++);
	f(); a++;
	printf("a value in function f():%d\n", a++);
	return 0;
}
