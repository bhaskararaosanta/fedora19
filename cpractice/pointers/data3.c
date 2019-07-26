#include<stdio.h>

int main()
{
	char *a;
	a = "DATA";
	printf("starting address stored in a:%p\n", a);
	while(*a)
	{
		printf("%c\n", *a++);
	}
	printf("last address stored in a:%p\n", a);
	return 0;
}
