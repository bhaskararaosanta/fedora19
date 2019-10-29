#include <stdio.h>

int main()
{
	float a = 10.55;
	int x, y, z;
	//x = 8++;
	 /* can't be used increment and decrement operators for
		    constants and expressions */
	a++;
	//y = ++x++;
	//z = (x+y)++;

	printf("x = %d, y = %d, z = %d, a =%f\n", x, y, z, a);

	return 0;
}
