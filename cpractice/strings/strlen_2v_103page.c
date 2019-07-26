#include<stdio.h>

int strlen(char *s)
{
	char *p = s;

	while(*p != '\0')
		p++;
	return p - s;
}

int main()
{
	char array[100] = "Bhaskar is a good boy";
	char *ptr = "Bhaskar is a good boy";
	int a, b, c;
	a = strlen("Bhaskar is a good boy"); //string constant
	b = strlen(array);                   //char array[100]
	c = strlen(ptr);                     //char *ptr;
	printf("String lengths for a, b, c:%d\t%d\t%d\n", a, b, c);
	return 0;
}


