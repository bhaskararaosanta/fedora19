#include<stdio.h>

/* we cannot use register qualifier for global variables */ 
/* register int a = 100; */

int a = 100;

int main()
{
	register int b = 200;
	/* we cannot assign register variable to pointer because register variables
	 * doesn't have any valid address hence below statemer is illegal */
	/* int *p = &b; */
	printf("value of a:%d\n", a);
	printf("value of b:%d\n", b);

	return 0;
}

