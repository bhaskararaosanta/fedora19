#include <stdio.h>

int main()
{
	int i, arr[10] = {25, 30, 35, 40, 55, 60, 65, 70, 85, 90};
	int *p = arr+9, *q = arr+1;
	printf("address of arr = %p, q = %p\n", arr, q);
	for(i = 0; i < 10; i++) {
		printf("%d ", *p--);
	}
	printf("\n");

	return 0;
}
