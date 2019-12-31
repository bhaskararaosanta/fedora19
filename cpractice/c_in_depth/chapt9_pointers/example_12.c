#include <stdio.h>

int main()
{
	int arr[5] = {3, 5, 6, 7, 9};
	int *p = arr;
	int (*ptr)[5] = &arr;
	printf("p = %p, ptr = %p\n", p, ptr);
	printf("*p = %d, *ptr = %p\n", *p, *ptr);
	printf("sizeof(p) = %d, sizeof(*p) =%d\n", sizeof(p), sizeof(*p));
	printf("sizeof(ptr) = %d, sizeof(*ptr) = %d\n", sizeof(ptr), sizeof(*ptr));
	
	return 0;
}
