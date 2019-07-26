#include<stdio.h>

int MAX(int x, int y)
{
	return ((x < y)? y: x);
}

int main()
{
	int a, b, c;
	scanf("%d%d", &a, &b);
	c = MAX(a, b);
	printf("Max is:%d\n", c);
	return 0;
}
