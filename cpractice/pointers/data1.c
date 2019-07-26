#include<stdio.h>

int main()
{
	char *a;
	a = "DATA";
	while(*a)
	{
		printf("%c\n", *a++);
	}
	return 0;
}
