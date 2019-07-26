#include<stdio.h>

int MAX(int x, int y)
{
	return ((x < y)? y: x);
}

int main()
{
	int a, b, c, d;
	scanf("%d%d%d", &a, &b, &c);
	d = MAX(MAX(a, b), c);
	printf("Max is:%d\n", d);
	return 0;
}
