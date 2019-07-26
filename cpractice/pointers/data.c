#include<stdio.h>

int main()
{
	char *a;
	a = "DATA";
	while(*a != '\0')
	{
		printf("%c\n", *a++);
	}
	return 0;
}
