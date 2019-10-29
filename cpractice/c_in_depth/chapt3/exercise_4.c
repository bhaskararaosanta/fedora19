#include <stdio.h>
#include <limits.h>

int main()
{
	int a = 4000000000;
	unsigned int b = 4000000000;
	printf("a = %d\nb = %u\n", a, b);
	printf("a = %d\nb = %u\n", INT_MAX, UINT_MAX);

	return 0;
}
