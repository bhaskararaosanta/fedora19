#include <stdio.h>

void func(int x, int y, int *psum, int *pdiff, int *pprod)
{
	*psum = x + y;
	*pdiff = x - y;
	*pprod = x * y;
}

int main()
{
	int a, b, sum, diff, prod;
	a = 6;
	b = 4;
	func(a, b, &sum, &diff, &prod);
	printf("sum = %d\ndiff = %d\nprod = %d\n", sum, diff, prod);

	return 0;
}

