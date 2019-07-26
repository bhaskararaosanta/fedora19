#include<stdio.h>

int main()
{
	int a[5][5], n, i, j;
	printf("Enter number of rows / columns:\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{	
		printf("Enter %dth row elements:\n", i);
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	}

	for(i = 0; i < n; i++)
	{	
		if(i % 2 == 0)
		{
			for(j = 0; j < n; j++)
			{
				printf("address:%p\tvalue:%d\t", &a[i][j], a[i][j]);
				printf("\t");
			}
			printf("\n");
		}
		else
		{
			for(j = n-1; j >= 0; j--)
			{
				printf("address:%p\tvalue:%d\t", &a[i][j], a[i][j]);
				printf("\t");
			}
			printf("\n");
		}

	}
	return 0;
}
