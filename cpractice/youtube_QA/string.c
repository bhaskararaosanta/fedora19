#include<stdio.h>
#include<string.h>

int main()
{
	int i, n;
	char x[] = "hello";
	n = strlen(x);
	printf("string length is:%d\n", n);
	x[0] = x[n-1];
	for(i = 0; i < n; ++i)
	{
		printf("%s\n", (x + i));
	}

	return 0;
}
