#include <stdio.h>

int main()
{
	int i, *p, arr[5] = {25, 30, 35, 40, 45};
	for(i = 0; i < 5; i++) {
		printf("%d\n", *arr);
		arr++;	/* arr will always point to same location 
			   and can't be incremented */
	}
	
	return 0;
}
