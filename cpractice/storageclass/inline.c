#include <stdio.h>

static inline int add(int x, int y)
{
	return (x + y);
}

int main()
{
	int a = 100, b = 200, c;
	c = add(a, b);
	printf("a+b=%d\n", c);
	return 0;
}

