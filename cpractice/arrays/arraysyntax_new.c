#include<stdio.h>

int main()
{
	char a[10], i;
	for(i = 0; i < 10; i++)
	{
		printf("Enter %dst/nd/rd/th element:", i+1);
		scanf("%d", (a+i));
	}

	for(i = 0; i < 10; i++)
	{

		printf("Printing %dst/nd/rd/th element and its address:", i+1);
		printf("%d\t%p", *(a+i), (a+i));
		printf("\n");
	}

	return 0;
}
