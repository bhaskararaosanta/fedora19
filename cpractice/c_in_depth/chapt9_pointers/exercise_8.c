#include <stdio.h>

int main()
{
	int i, *p, arr[5] = {25, 30, 35, 40, 45};
	p = arr;
	for(i = 0; i < 5; i++) {
		printf("%d\t", *p++);
	}
	printf("\n");
	
	for(i = 0; i < 5; i++) {
		printf("%d\t", *--p);
	}
	printf("\n");
	
	return 0;
}
