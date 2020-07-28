#include <stdio.h>
//#define	run	40
//#if !(run^run)
//#error bhaskar it is an error
//#endif

//#define	GoOn
int main(void) 
{
	printf("Hello, world\n");
#ifndef GoOn
#error Bhaskar you had done enough and stop execution
#endif

	return 0;
}
