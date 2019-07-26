/* program to illustrate here b and c are not defined and it will give compiler error */
#include<stdio.h>

int main()
{
	int a = b = c = 10;
	a = b = c = 50;
	printf("a:%d\tb:%d\tc:%d\n", a, b, c);
	return 0;
}
