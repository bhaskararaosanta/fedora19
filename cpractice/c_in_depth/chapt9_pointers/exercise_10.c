#include <stdio.h>

int main()
{
	int arr[10] = {25, 30, 35, 40, 55, 60, 65, 70, 85, 90}, *p;
	for(p = &arr[0]; p < arr+10; p++) {
		printf("%p ", p);
	}
	printf("\n");

	return 0;
}
