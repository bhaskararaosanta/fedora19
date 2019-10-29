#include <stdio.h>

int main()
{
	int a = 10, b = 3, max;
	// a>b? max=a : max=b; 
	/* since the precedence of assignment operator
	is less than that of conditional operator, the conditional statement interpreted
	as (a>b?max=a:max)=b; which results in 10=b which gives lvalue required error.
	Hence following is the correct representation of the above expression */

	a>b? max=a : (max=b);
	printf("max=%d\n", max);

	return 0;
}
