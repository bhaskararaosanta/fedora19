#include<stdio.h>

#define	row	3
#define col	4

int main()
{
	int i, j;
	int arr[row][col] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
			printf("%d\t", arr[i][j]);
	printf("\n");
	}
	printf("address of 0th 1-dimension array:%u\n", arr);
	printf("address of 1st 1-dimension array:%u\n", arr+1);
	printf("address of 2nd 1-dimension array:%u\n", arr+2);
	
	printf("base address of 0th 1-dimension array:%u\n", *arr);
	printf("base address of 1st 1-dimension array:%u\n", *(arr+1));
	printf("base address of 2nd 1-dimension array:%u\n", *(arr+2));
	
	printf("base address of 0th 1-dimension array:%u\n", *arr+1);
	printf("base address of 1st 1-dimension array:%u\n", *(arr+1)+1);
	printf("base address of 2nd 1-dimension array:%u\n", *(arr+2)+1);
	return 0;
}

