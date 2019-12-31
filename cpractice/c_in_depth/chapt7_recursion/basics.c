#include <stdio.h>

int fact(int n)
{
	printf("I am calculating F(%d)\n", n);
	if(n == 0) {
		return 1;
	}
	int F = n * fact(n-1);
	printf("Done F(%d) = %d\n", n, F);
	return F;
}

int main()
{
	int m;
	printf("Enter number less than 10 to find factorial:");
	scanf("%d", &m);
	printf("Factorial of m:%d\n", fact(m));

	return 0;
}
