#include<stdio.h>

int PRIME(int n)
{
	int i;
	for(i = 2; i < n; i++)
	{
		if(n%i == 0)
		{	printf("n inside fun:%d\n", n);
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	(PRIME(n))? printf("yes\n"): printf("no\n");
	return 0;
}
