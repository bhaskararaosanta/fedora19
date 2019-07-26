#include<stdio.h>

int g = 100;

void change()
{
	g = 200;
	printf("value of g in change function:%d\n", g);
	return;
}

int main()
{
	change();
	g = 300;
	printf("value of g in main:%d\n", g);
	return 0;
}
