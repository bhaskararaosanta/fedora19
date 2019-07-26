#include<stdio.h>

int main()
{
	int a[3] = {10, 20, 30};
	int *ptr[3], i;
	for(i = 0; i < 3; i++)
	{
		printf("address of array elements:%p\n", a+i);
		ptr[i] = &a[i];
	}
	printf("Elements of the array are:");

	for(i = 0; i < 3; i++)
	{
		printf("addresses stored in array pf pointers:%p\n", ptr[i]);
		printf("values pointed by array of pointers:%d\n", *ptr[i]);
	}
	printf("\n");
	return 0;	
}
