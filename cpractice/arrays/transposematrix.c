#include<stdio.h>

int main()
{
	int a[4][4], n, i, j, s1 = 0, s2 = 0, temp;
	printf("Enter number of rows / columns:\n");
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{	
		printf("Enter %dth row elements:\n", i);
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

	}

	for(i = 1; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			temp = a[i][j];
			a[i][j] = a[j][i];
			a[j][i] = temp;
		}
	}
	printf("s1:%d\ts2:%d\n", s1, s2);

	printf("Address of n:%p\ti:%p\tj:%p\ts1:%p\ts2:%p\ttemp:%p\n", &n, &i, &j, &s1, &s2, &temp);
	for(i = 0; i < n; i++)
	{	
		for(j = 0; j < n; j++)
		{
			printf("address:%p\tvalue:%d\t", &a[i][j], a[i][j]);
			printf("\t");
		}
			printf("\n");
	}
	return 0;
}
