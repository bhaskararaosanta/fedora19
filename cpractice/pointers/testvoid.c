#include<stdio.h>

int main()
{
	void *v;
	char *c;
	c = "Testing void pointer";
	v = c;
	printf("%s\n", v);
	return 0;
}
