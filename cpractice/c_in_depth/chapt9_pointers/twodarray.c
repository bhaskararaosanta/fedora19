#include <stdio.h>

#define	N	6
int main()
{
	int i, j, arr[N] = {10, 20, 30, 40, 50, 60};
	int *p = arr;	// p is a pointer to arr[0] element
	int (*ptr)[6] = &arr;	// ptr is pointer to a
				// complete array of 5 elements
	printf("Address contained in p:%p\t%u\n", p, p);
	printf("Address contained in ptr:%p\t%u\n", ptr, ptr);
	printf("\n\n");
	for(i = 0; i < N; i++) {
		printf("address of a[%d] = %p\n", i, (p+i));
		printf("address of a[%d] = %p\n", i, *ptr+i);
	}
	printf("\n\n");
	printf("after p++ and ptr++ printing values.\n");
	p++;	// incrementing p to next integer in array
	ptr++;	// incrementing ptr to point to next array of 6 ints
	printf("Address contained in p:%p\t%u\n", p, p);
	printf("Address contained in ptr:%p\t%u\n", ptr, ptr);

	return 0;
}

