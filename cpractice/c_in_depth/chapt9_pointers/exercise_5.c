#include <stdio.h>

int main()
{
	int i, *p, arr[5] = {25, 30, 35, 40, 45};
	p = &arr[4];
	for(i = 0; i < 5; i++) {
		printf("%d\t%d\n", *(p-i), p[-i]); // pointer in array notation
	}
	
	return 0;
}
