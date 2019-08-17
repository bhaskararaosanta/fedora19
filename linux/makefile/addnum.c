#include<stdio.h>

extern int addnumbers(int , int );

int main()
{
	int sum;
	int a = 10;
	int b = 20;

	sum = addnumbers(a, b);
	printf("sum of numbers a and b:%d\n", sum);
//	printf("sum of numbers a and b:%d\n", a+b);
	return 0;
}
