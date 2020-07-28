#include <stdio.h>

int main()
{
	int a = 10, b = 20;

#warning	This is kind of warning but compilation will continue

	printf("Hello warning message is displayed\n");

//#error	compilation will stop by showing this message as error

	return 0;
}
