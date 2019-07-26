#include<stdio.h>

#define	rows	3
#define	cols	4

int main()
{
	int i, j;
	int arr[rows][cols] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	int barr[rows][cols];

	int *p = (int *)0x300000;
	printf("value at random location of 0x300000 is:%d\n", (int *)0x300000);

	printf("address of arr:%p\n", &arr);
	printf("address of arr:%p\n", arr);

	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("address of arr[%d][%d]:%p:", i, j, &arr[i][j]);
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("Value of i outside for loop:%d\n", i);

	printf("\n");
	printf("address of 1st row or oth 1-D array:%p\t%p\n", arr, arr[0]);
	printf("address of 2nd row or 1st 1-D array:%p\t%p\n", arr+1, arr[1]);
	printf("address of 3rd row or 2nd 1-D array:%p\t%p\n", arr+2, arr[2]);

	printf("address of 1st row and 0th element:%p\t%p\n", *arr, &arr[0][0]);
	printf("address of 2nd row and 0th element:%p\t%p\n", *(arr+1), &arr[1][0]);
	printf("address of 3rd row and 0th element:%p\t%p\n", *(arr+2), &arr[2][0]);

	printf("address of 1st row and 1st element:%p\t%p\n", *arr+1, &arr[0][1]);
	printf("address of 2nd row and 1st element:%p\t%p\n", *(arr+1)+1, &arr[1][1]);
	printf("address of 3rd row and 1st element:%p\t%p\n", *(arr+2)+1, &arr[2][1]);
	
	printf("address of 1st row and 2nd element:%p\t%p\n", *arr+2, &arr[0][2]);
	printf("address of 2nd row and 2nd element:%p\t%p\n", *(arr+1)+2, &arr[1][2]);
	printf("address of 3rd row and 2nd element:%p\t%p\n", *(arr+2)+2, &arr[2][2]);

	printf("address of 1st row and 3rd element:%p\t%p\n", *arr+3, &arr[0][3]);
	printf("address of 2nd row and 3rd element:%p\t%p\n", *(arr+1)+3, &arr[1][3]);
	printf("address of 3rd row and 3rd element:%p\t%p\n", *(arr+2)+3, &arr[2][3]);
	
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			barr[i][j] = arr[i][j];
		}
	}
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("address of barr[%d][%d]:%p:", i, j, &barr[i][j]);
			printf("%d\t", barr[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
