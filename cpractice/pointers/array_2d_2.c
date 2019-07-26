#include<stdio.h>

#define	ROWS	3
#define	COLS	4

int main()
{
	int i, j;
	int arr[ROWS][COLS] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

	int barr[ROWS][COLS];

	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			printf("Address where arr[%d][%d] stored:%p  and the value it stored:%d\n", i, j, \
					&arr[i][j], arr[i][j]);
		}
		printf("\n\n");
	}

	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			printf("Address where barr[%d][%d] stored:%p  and the value it stored:%d\n", i, j, \
					&barr[i][j], barr[i][j]);
		}
		printf("\n\n");
	}

	for(i = 0; i < ROWS; i++)
	{
		printf("Address of %d th row pointer:%p\t%p\n", i, arr+i, arr[i]);
		for(j = 0; j < COLS; j++)
		{
			printf("Address of %d th row of %d th col element:%p\t%p\t%p\n", i, j, &arr[i][j], \
					(*(arr+i)+j), (arr[i]+j));
		}
		printf("\n\n");
	}

	for(i = 0; i < ROWS; i++)
	{
		printf("Values of %d th row pointer pointing:%d\t%d\n", i, **(arr+i), *arr[i]);
		for(j = 0; j < COLS; j++)
		{
			printf("Address of %d th row of %d th col element:%d\t%d\t%d\n", i, j, *(&arr[i][j]), \
					*(*(arr+i)+j), *(arr[i]+j));
		}
		printf("\n\n");
	}

	return 0;
}
