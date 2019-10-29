#include <stdio.h>

int main()
{
	int x, y, u, v;
	int a = 5;
	int *p;
	p = &a;
	printf("Value of p = Address of a = %p\n", p);
	printf("Value of p = %p\n", ++p);
	printf("Value of p = %p\n", p++);
	printf("Value of p = %p\n", p);
	printf("Value of p = %p\n", --p);
	printf("Value of p = %p\n", p--);
	printf("Value of p = %p\n", p);
	printf("\n");
	
	a = 5;
	p = &a;
	x = *p++;
	printf("Value of x after x = *p++ : %d and p: %p\n", x, p);
	a = 5;
	p = &a;
	y = *++p;
	printf("Value of y after y = *++p : %d and p: %p\n", y, p);
	a = 5;
	p = &a;
	u = ++*p;
	printf("Value of u after u = ++*p : %d and p: %p\n", u, p);
	a = 5;
	p = &a;
	v = (*p)++;
	printf("Value of u after v = (*p)++ : %d and p: %p\n", v, p);
	printf("Value of a:%d\n", a);

	return 0;
}
