#include<stdio.h>
#define	M	3
#define	N	4
int main()
{
	int a[M][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	//int a[M][N];
	int i, j;
	for(i = 0; i < M; i++)
	{
		printf("pointers to row and next row etc is:a+i:%p\t%p\n", a+i, a[i]); 
		printf("address and values of first row elements:");
		for(j = 0; j < N; j++)
		{
			printf("%p - %d\t", &a[i][j], a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
	
