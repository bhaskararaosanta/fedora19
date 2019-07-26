#include<stdio.h>

int main()
{
	int a[4][5], nr, nc, i, j;
	printf("Enter number of rows and columns:\n");
	scanf("%d%d", &nr, &nc);
	for(i = 0; i < nr; i++)
	{	
		printf("Enter %dth row elements:\n", i);
		for(j = 0; j < nc; j++)
			scanf("%d", &a[i][j]);

	}

	for(i = 0; i < nr; i++)
	{	
		for(j = 0; j < nc; j++)
		{
			printf("address:%p value:%d ", &a[i][j], a[i][j]);
			printf("\t");
		}
			printf("\n");
	}
	return 0;
}
