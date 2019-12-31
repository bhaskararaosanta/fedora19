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
#error I had enough
#endif

	return 0;
}
