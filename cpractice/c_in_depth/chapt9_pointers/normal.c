#include <stdio.h>

int main()
{
	int i, *p, arr[6] = {10, 20, 30, 40, 50, 60};
	for(i = 0; i < 6; i++) {
		printf("address of arr[%d] = %p\n", i, &arr[i]);
		printf("value of arr[%d] = %d\n", i, arr[i]);
	}
	printf("\n");

	p = arr;
	printf("value of *++p after p = arr: %d\n", *++p);
	arr[0] = 10;
	p =arr;
	printf("value of ++*p after p = arr: %d\n", ++*p);
	arr[0] = 10;
	p = arr;
	printf("value of *p++ after p = arr: %d\n", *p++);
	printf("value of *p++ after p = arr: %d\n", *p);
	arr[0] = 10;
	p = arr;
	printf("value of (*p)++ after p = arr: %d\n", (*p)++);
	printf("value of (*p)++ after p = arr: %d\n", *p);
	arr[0] = 10;
	p = arr;
	printf("value of ++(*p) after p = arr: %d\n", ++(*p));


	return 0;
}
