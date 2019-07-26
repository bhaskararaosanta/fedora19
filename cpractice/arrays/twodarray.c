#include<stdio.h>

#define	r	3
#define	c	4

int main()
{
	int i, j, k = 0;
	int a[r][c] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	printf("size of array is:%d\n", sizeof(a));
	printf("starting address of each row:%p\t%p\t%p\n", a, a+1, a+2);
	for(i = 0; i < r; i++)
	{
		for(j = 0; j < c; j++)
		{
			k++;
			printf("%d\t%d\t", a[i][j], *(*(a+i)+j));
		}
		printf("\n");
	}
	printf("starting address of 0th row:%p\n%p\n%p\n%p\n%p\n%p\n%p\nand value of first element:%d\n", a, a+0, (a+0)+0, &a[0], &a[0][0], *(a+0), *(a+0)+0, *(*(a+0)+0));
	printf("Starting address of 1st row:%p\n%p\n%p\n%p\n", a+1, (a+0)+1, &a[1], &a[1][0]); 
	printf("Starting address of 2nd row:%p\n%p\n%p\n%p\n", a+2, (a+0)+2, &a[2], &a[2][0]); 
	for(j = 0; j < c; j++)
	{
		printf("%d\t", k);
	}
	printf("\n");
	return 0;
}
