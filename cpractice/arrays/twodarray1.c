#include<stdio.h>

int main()
{
	int r, c;
	int ar[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
	for(r = 0; r < 3; r++)
	{
		for(c = 0; c < 4; c++)
			printf("%d\t", ar[r][c]);
	printf("\n");
	}
	return 0;
}
