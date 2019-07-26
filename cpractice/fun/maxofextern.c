#include<stdio.h>
#include "extern.c"

int main()
{
	int a, b, c, d;
	scanf("%d%d%d", &a, &b, &c);
	d = MAX(MAX(a, b), c);
	printf("Max is:%d\n", d);
	return 0;
}
