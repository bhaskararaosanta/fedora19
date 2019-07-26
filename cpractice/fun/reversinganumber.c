#include<stdio.h>

int REV(int n)
{
	int s = 0;
	while(n)
	{
		s = s * 10 + n%10;
		n = n / 10;
	}
	return s;
}

int main()
{
	int n, rn;
	scanf("%d", &n);
	rn = REV(n);
	printf("%d\t%d\n", n, rn);
}
