#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *a, b[256];
	printf("Enter a string:");
	gets(b);
	if((a =  (char*)malloc(strlen(b))) == NULL)
	{
		printf("out of memory\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		strcpy(a, b);
		puts(a);
	}

	return 0;
}
