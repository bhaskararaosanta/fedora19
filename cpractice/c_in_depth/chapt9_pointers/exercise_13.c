#include <stdio.h>

int main()
{
	int arr[10] = {25, 30, 35, 40, 55, 60, 65, 70, 85, 90}, *p;
	for(p = arr+9; p >= arr; p--) {
		printf("%d ", *p);
	}
	printf("\n");

	return 0;
}