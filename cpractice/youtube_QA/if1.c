#include<stdio.h>

int main()
{
	int a = 2;
	//if(a--, --a, a)
	if(--a, a, a--)
		printf("Yes");
	else
		printf("No");

	printf("value of a:%d\n", a);
	return 0;
}
