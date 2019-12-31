#include <stdio.h>

int main()
{
	int a[5] = {1}, b[5] = {1};
	if(a == b) {
		printf("same\n");
	}
	else {
		printf("different\n");
	}
	printf("address of a = %p, b = %p\n", a, b);

	return 0;
}
