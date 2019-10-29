#include <stdio.h>

int main()
{
	int *p;		/* can point an integer */
	int (*ptr)[5];	/* can point to an array of 5 integers */
	int arr[5];
	p = arr;	/* p points to an 0th element of the array */
	ptr = &arr;	/* ptr points to the whole array */
	printf("p = %p, ptr = %p\n", p, ptr);
	p++;
	ptr++;
	printf("printing after incrementing p++ and ptr++\n");
	printf("p = %p, ptr = %p\n", p, ptr);

	return 0;
}
