#include <stdio.h>

int main()
{
	int arr[5], i;
	for(i = 0; i < 5; i++) {
		printf("%p ", arr+i);
	}
	printf("\nEnter 5 numbers:");
	for(i = 0; i < 5; i++) {
		scanf("%d", arr+i);
	}
	for(i = 0; i < 5; i++) {
		printf("%d ", *(arr+i));
	}
	printf("\n");

	return 0;
}

