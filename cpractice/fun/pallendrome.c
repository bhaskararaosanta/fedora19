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

int ISPALIN(int n)
{
	return(n == REV(n));
}

int main()
{
	int n;
	scanf("%d", &n);
	(ISPALIN(n))? printf("yes\n"):printf("no\n");
}
