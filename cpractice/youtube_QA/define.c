#include<stdio.h>

#define	square(x)	x*x

int main()
{
	int a = 10;
	int b = square(a+4);
	printf("a = %d\nb = %d\n", a, b);
	return 0;
}
