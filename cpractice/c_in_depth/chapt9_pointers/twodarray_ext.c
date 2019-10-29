#include <stdio.h>

#define	M	3
#define	N	4

int main()
{
	int i, j;
	int arr[M][N] = {{1, 2, 3, 4}, {10, 20, 30, 40}, {100, 200, 300, 400}};

	int (*ptr)[N] = arr;
	printf("Address of arr 0th row using pointer ptr:%p\n", ptr);	
	printf("Address of arr 1st row using pointer ptr:%p\n", ptr+1);	
	printf("Address of arr 2nd row using pointer ptr:%p\n", ptr+2);	
	for(i = 0; i < M; i++) {
		for(j = 0; j < N; j++) {
			printf("value of arr[%d][%d] = %d\tAddress of arr[%d][%d] = %p\n", i, j, arr[i][j], i, j, &arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("Address of 0th 1-D array:%p\n", arr);
	printf("Address of 1st 1-D array:%p\n", arr+1);
	printf("Address of 2nd 1-D array:%p\n", arr+2);

	printf("Address of 0th 1-D array 0th element:%p\n", *(arr+0)+0);
	printf("Address of 0th 1-D array 1st element:%p\n", *(arr+0)+1);
	printf("Address of 0th 1-D array 2nd element:%p\n", *(arr+0)+2);
	printf("Address of 0th 1-D array 3rd element:%p\n", *(arr+0)+3);

	printf("Address of 1st 1-D array 0th element:%p\n", *(arr+1)+0);
	printf("Address of 1st 1-D array 1st element:%p\n", *(arr+1)+1);
	printf("Address of 1st 1-D array 2nd element:%p\n", *(arr+1)+2);
	printf("Address of 1st 1-D array 3rd element:%p\n", *(arr+1)+3);
	
	printf("Address of 2nd 1-D array 0th element:%p\n", *(arr+2)+0);
	printf("Address of 2nd 1-D array 1st element:%p\n", *(arr+2)+1);
	printf("Address of 2nd 1-D array 2nd element:%p\n", *(arr+2)+2);
	printf("Address of 2nd 1-D array 3rd element:%p\n", *(arr+2)+3);
	
	printf("Value of 0th 1-D array 0th element:%4d\n", *(*(arr+0)+0));
	printf("Value of 0th 1-D array 1st element:%4d\n", *(*(arr+0)+1));
	printf("Value of 0th 1-D array 2nd element:%4d\n", *(*(arr+0)+2));
	printf("Value of 0th 1-D array 3rd element:%4d\n", *(*(arr+0)+3));

	printf("Value of 1st 1-D array 0th element:%4d\n", *(*(arr+1)+0));
	printf("Value of 1st 1-D array 1st element:%4d\n", *(*(arr+1)+1));
	printf("Value of 1st 1-D array 2nd element:%4d\n", *(*(arr+1)+2));
	printf("Value of 1st 1-D array 3rd element:%4d\n", *(*(arr+1)+3));
	
	printf("Value of 2nd 1-D array 0th element:%4d\n", *(*(arr+2)+0));
	printf("Value of 2nd 1-D array 1st element:%4d\n", *(*(arr+2)+1));
	printf("Value of 2nd 1-D array 2nd element:%4d\n", *(*(arr+2)+2));
	printf("Value of 2nd 1-D array 3rd element:%4d\n", *(*(arr+2)+3));
	
	return 0;
}
