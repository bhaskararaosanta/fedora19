#include <stdio.h>

#define	N	6

int main()
{
	int i, j, temp, totalmoves = 0, arr[N];
	printf("Enter %d array elements:", N);
	for(i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Entered array elements:");
	for(i = 0; i < N; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");

	for(i = 0; i < N-1; i++) {
		for(j = i+1; j < N; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				++totalmoves;
			}
		}
	}
	
	printf("Sorted array elements:");
	for(i = 0; i < N; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	printf("No of moves required to sort array:%d\n", totalmoves);

	return 0;
}
