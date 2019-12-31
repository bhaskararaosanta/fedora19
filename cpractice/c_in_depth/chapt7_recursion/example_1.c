#include <stdio.h>

int series(int);

int main()
{
	int n;
	printf("Enter number of terms:");
	scanf("%d", &n);
	printf("series sum = %d\n", series(n));

	return 0;
}

int series(int m)
{
	printf("Calculation begins method number:%d\n", m);
	int sum = 0;
	if(m == 0) {
		return 0;
	}
	sum = m + series(m-1);
	printf("End of method number:%d\n", m);
	return sum;
}

