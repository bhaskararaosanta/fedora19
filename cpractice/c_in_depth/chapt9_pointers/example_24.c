#include <stdio.h>

int main()
{
	int *pa[4];
	int i, arr[4] = {5, 10, 15, 20};
	for(i = 0; i < 4; i++) {
		printf("address of arr[%d] = %p\n", i, &arr[i]);
		pa[i] = &arr[i];
	}
	for(i = 0; i < 4; i++) {
		printf("pa[%d] = %p\t", i, pa[i]);
		printf("*pa[%d] = %d\n", i, *pa[i]);
	}

	return 0;
}
