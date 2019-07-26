#include<stdio.h>

/* global variable */
int num;

void display()
{
	int i;
	for(i = 0; i <= num; i++)
	{
		printf("num = %d\n", num);
	}
}
