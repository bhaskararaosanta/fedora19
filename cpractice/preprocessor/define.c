#include<stdio.h>

#define CONST	100

int main()
{
	printf("address of main function:%p\n", main);
	printf("value of unassigned define constant:%d\n", CONST);
	printf("value of unassigned constant:%d\n");
	printf("value of unassigned constant:%d\n", 2000);
	printf("value of unassigned constant:%d\n");
	return 0;
}
