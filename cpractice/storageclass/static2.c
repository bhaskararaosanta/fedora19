#include<stdio.h>

int counterFunction()
{
	static int count = 0;
	count++;
	return count;
}

int main()
{
	printf("First counter output = %d\n", counterFunction());
	printf("Second counter output = %d\n", counterFunction());

	return 0;
}
