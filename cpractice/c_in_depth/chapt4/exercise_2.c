#include <stdio.h>

int main()
{
	int a = 2, b = 1, c, d;
	c = a < b;
	d = (a > b) && (c < b);
	printf("c = %d\nd = %d\n", c, d);

	return 0;
}
