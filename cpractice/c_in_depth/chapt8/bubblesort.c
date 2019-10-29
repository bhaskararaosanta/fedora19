#include <stdio.h>

#define	N	6

int main()
{
	int i, j, temp, totalmoves = 0, arr[N];
	printf("Enter  %d array elements:", N);
	for(i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Entered array elements:");
	for(i = 0; i < N; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	for(i = 0; i < N-1; i++) {
		for(j = 0; j < N-1-i; j++) {
			if(arr[j] > arr[j+1]) {
			temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
			++totalmoves;
			}
		}
	}

	printf("sorted array elements are:");
	for(i = 0; i < N; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("total moves taken to sort array:%d\n", totalmoves);

	return 0;
}

