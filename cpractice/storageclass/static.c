#include <stdio.h>

int main()
{
	static int i = 15;
    	if(--i)
	{
        	main();
        	printf("%d ",i);
    	}
	return 0;
}
