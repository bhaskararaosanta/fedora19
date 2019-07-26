#include<stdio.h>

int main()
{
	int x = 5;
	int *p = &x;
	printf("*p = &x\n");
	printf("value in x:%d\t and address of x:%p\n", x, &x);
	printf("value in p:%p\t and address of p:%p\n", p, &p);
	int *k = p++;
	p = p + 3;
	printf("int *k = p++\n");
	printf("value in k:%p\t and address of k:%p\n", k, &k);
	printf("value in p:%p\t and address of p:%p\n", p, &p);
	int r = p - k;
	printf("int r = p - k\n");
	printf("value in r:%p\t and address of r:%p\n", r, &r);
	return 0;
}
