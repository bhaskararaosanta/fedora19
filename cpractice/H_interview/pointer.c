#include <stdio.h>

int *fun1(void)
{
	int x;
	int *ptr1 = &x;
	printf("address of ptr1:%p\n", ptr1);
	return ptr1;
}

int *fun2(void)
{
	int y;
	int *ptr2 = &y;
	printf("address of ptr2:%p\n", ptr2);
	return ptr2;
}

int main()
{
	int a, b;
	a = (int)fun1();
	b = (int)fun2();
	printf("a = %p\nb = %p\n", (int *)a, (int *)b);
	
	return 0;
}
