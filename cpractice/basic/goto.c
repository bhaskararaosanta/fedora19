#include <stdio.h>

int main()
{
	int i = 1;
	here:
	{
		printf("PP\n");
	}
	while(i <= 5)
	{
		printf("%d\n", i);
		if(i > 2)
			goto here;
		i++;
	}

	return 0;
}

/*void fun(void)
{
	here:
	printf("PP\n");
}*/
