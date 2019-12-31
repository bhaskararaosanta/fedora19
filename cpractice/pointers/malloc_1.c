#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *a, b[256];
	printf("enter a string:");
	gets(b);
	/* void *malloc(size_t size); */
	if((a = (char *)malloc(sizeof(b))) == NULL) {
		printf("memory assigned is failed\n");
		exit(1);
	}
	else {
		printf("memory where a and b are assigned:%p\t%p\n", a, b);
		printf("first character in assigned dynamic memory:%d\n", *a);
		strcpy(a, b);
		puts(a);
	}

	/* void *calloc(size_t nmemb, size_t size); */
	printf("Enter different string for testing calloc function:");
	gets(b);
	if((a = (char *)calloc(256, sizeof(char))) == NULL) {
		printf("memory assigned is failed using calloc.\n");
		exit(1);
	}
	else {
		printf("memory assigned is failed using calloc.\n");
		printf("first character in assigned dynamic memory:%d\n", *a);
		strcpy(a, b);
		puts(a);
	}

	return 0;
}
