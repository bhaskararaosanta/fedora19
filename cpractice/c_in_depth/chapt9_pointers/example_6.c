#include <stdio.h>

int main()
{
	int a = 5;
	int *ptra;
	int **ptrptra;
	ptra = &a;
	ptrptra = &ptra;
	printf("Address of a = %p\n", &a);
	printf("Value of ptra = Address of a = %p\n", ptra);
	printf("Value of *ptra = value of a = %d\n", *ptra);
	
	printf("Address of ptra = %p\n", &ptra);
	printf("Value of ptrptra = Address of ptra = %p\n", ptrptra);
	printf("Value of *ptrptra = value of ptra = %p\n", *ptrptra);
	printf("Value of **ptrptra = value of a = %d\n", **ptrptra);
	printf("Address of ptrptra = %p\n", &ptrptra);

	return 0;
}
