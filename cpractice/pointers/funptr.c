#include<stdio.h>

int add(int a, int b)
{
	return a+b;
}

int main()
{
	int x, y, z;
	int (*addfunptr)(int, int);
	printf("Enter two numbers to add using function pointer:");
	scanf("%d%d", &x, &y);

	//addfunptr = &add;      and below statement also works like this.
	addfunptr = add;

	printf("memory address at which add function stored:%p\t%p\n", addfunptr, add);
	z = addfunptr(x, y);
	printf("sum of x and y is:%d\n", z);

	return 0;
}
