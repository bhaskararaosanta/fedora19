#include <stdio.h>

int main()
{
	int a[2][3];
	a[1][2] =9;
	printf("%d\n", a[1,2]);
	
	printf("address of a[1][2] = %p\n", &a[1,2]);
	printf("address of a[1][2] = %p\n", &a[1][2]);
	
	return 0;
}
