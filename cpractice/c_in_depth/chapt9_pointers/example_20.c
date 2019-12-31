#include <stdio.h>

void func(int a[])
{
	int i;
	printf("Inside func():\n");
	for(i = 0; i < 5; i++) {
		a[i] = a[i] + 2;
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int i, arr[5] = {3, 6, 3, 7, 1};
	func(arr);
	printf("Inside main():\n");
	for(i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
