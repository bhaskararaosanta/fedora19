#include<stdio.h>

static int i = 100;

void fun(void)
{
	printf("value of i inside function fun:%d\n", i);
}

int main()
{
	static int i = 200;
	/* static int i;  in this case value of i initialized to 0 */
	printf("value of i inside main:%d\n", i);
	fun();

	return 0;
}
