#include <stdio.h>

int *func(int *p, int n)
{
	p = p + n;
	return p;
}

int main()
{
	int n = 5, arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int *ptr;
	ptr = func(arr, n);
	printf("Value of arr = %p\nValue of ptr = %p\nValue of *ptr = %d\n", arr, ptr, *ptr);

	return 0;
}
