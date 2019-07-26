#include<stdio.h>
#include<stdlib.h>

int a = 100; /* by default global variables assigned with value 0 */

int main()
{
	int a = 200;
	static int b = 300;  /* by default static variables assigned with value 0 */
	{	
		printf("value of a inside block:%d\n", a);
		printf("value of b inside block:%d\n", b);
	}
	printf("value of a inside main function:%d\n", a);
	printf("value of b inside main function:%d\n", b);

	return 0;
}
	
