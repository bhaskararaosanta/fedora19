#include<stdio.h>

void PRINT(int * x)
{
	printf("%d\n",*x);
	*x = 20;
	printf("%d\n",*x);
}

int main()
{
	int a = 10;
	PRINT(&a);
	printf("%d\n",a);
	return 0;
}
