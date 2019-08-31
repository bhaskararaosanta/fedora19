#include <stdio.h>

int main()
{
	/* int c = --2;  we can't use post and pre increment and decrement
		operators directly to constants and those can only be used with
		only variables and hence "lvalue required" error will generate. */ 
	
	int d = - -2;
	
	printf("d = %d\n", d);
	printf("ascii of backslash n and 'a' are:%d %d\n", '\n', 'a');

	return 0;
}
