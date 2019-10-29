#include <stdio.h>

int main()
{
	int a = 10;
	float b = 123.1265;
	printf("b = %f\n", b);
	printf("b = %d (above float printing in decimal)\n", b);
	printf("b = %d (float printing in decimal with typecast)\n", (int)b);
	printf("a = %f (above int printing in flaot)\n", a);
	printf("a = %f (int printing in flaot with typecast)\n", (float)a);
	printf("%.2f\n", b);
	printf("%.3f\n", b);
	printf("%2.3f\n", b);
	printf("%15.3f\n", b);

	return 0;
}
