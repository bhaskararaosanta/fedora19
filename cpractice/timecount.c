#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0, j = 0;
	for(;;)
	{
		sleep(10);
		i = i+10;
		printf("time elapsed:%4d\tseconds\n\a", i);
		printf("for loop run approximately %d times without any delay and this is the power of modern computer.\n", j++); 
	}
	return 0;
}
