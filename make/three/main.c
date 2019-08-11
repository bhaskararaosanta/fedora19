#include<stdio.h>
extern int add(int, int);

int main()
{
	int a = 10, b = 20, c;
	c = add(10, 20);
	printf("value of c is:%d\n", c);

	return 0;
}

