#include <stdio.h>

//static int i;

int main()
{
	int x = 10;
	int y;
	{
		y = x++;
	}
	printf("%d", x);
	//int i;
	//printf("%d\n", i);

	return 0;
}
