#include <stdio.h>

void display(int a)
{
	static int p = 1;
	p++;
	p = 6;
	printf("\np value:%d\t a value:%d\n", p, a);
}

int main()
{
	display(60);
	display(70);
	display(80);
	display(90);

	return 0;
}
