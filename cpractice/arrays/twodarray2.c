#include<stdio.h>

#define	ROWS	3
#define	COLS	4

int main()
{
	int i, j, arr_2d[ROWS][COLS];
	int (*p)[4] = arr_2d;

	printf("address of pointer and array:%p\t%p\t%p\t%p\n", p, arr_2d, arr_2d[0], (arr_2d + 0));
	printf("address of pointer increment and next 1-D array address:%p\t%p\t%p\n", ++p, arr_2d[1], (arr_2d + 1));
	printf("address of pointer increment and next 1-D array address:%p\t%p\t%p\n", ++p, arr_2d[2], (arr_2d + 2));

	
	for(i = 0; i < ROWS; i++)
	{
		printf("Enter %d row elements with each by space:", i);
		for(j = 0; j < COLS; j++)
		{
			scanf("%d", &arr_2d[i][j]);
		//	scanf("%d", (*(arr_2d + i) + j)); it will also works like above
		}
		printf("\n");
	}
	
	for(i = 0; i < ROWS; i++)
	{
		printf("Printing %d row elements with each by space:", i);
		for(j = 0; j < COLS; j++)
		{
			printf("%d\t%d\t%d\t", arr_2d[i][j], *(arr_2d[i] + j), *(*(arr_2d + i) + j));
		}
		printf("\n");
	}

	for(i = 0; i < ROWS; i++)
	{
		printf("Printing %d row elements address with each by space:", i);
		for(j = 0; j < COLS; j++)
		{
			printf("%p\t%p\t", &arr_2d[i][j], (*(arr_2d + i) + j));
		}
		printf("\n");
	}

	return 0;
}
