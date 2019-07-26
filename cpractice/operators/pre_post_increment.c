#include<stdio.h>

int main()
{
	int a = 10, b = 20, c;
	c = ++a + ++b + ++a;
	printf("values of a:%d b:%d c:%d\n", a, b, c);

	a = 10;
       	b = 20;
	c = ++a + b++ + ++a;
	printf("values of a:%d b:%d c:%d\n", a, b, c);

	a = 10;
       	b = 20;
	c = a++ + b++ + a++;
	printf("values of a:%d b:%d c:%d\n", a, b, c);
	
	a = 10;
       	b = 20;
	c = a++ + ++b + ++a;
	printf("values of a:%d b:%d c:%d\n", a, b, c);

	return 0;
}

