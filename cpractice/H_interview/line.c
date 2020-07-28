#include <stdio.h>

int main()
{
	printf("%s\t%d\n", __FILE__, __LINE__);
#line 15 "try.c" // line directive is used to reset the line number of the source code
	printf("%s\t%d\n", __FILE__, __LINE__);
	printf("%s\t%d\n", __FILE__, __LINE__);

	return 0;
}
