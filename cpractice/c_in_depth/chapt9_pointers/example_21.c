#include <stdio.h>

void func(double *d, int *i, char *c) // below line can be written like this also
//void func(double d[], int *i, char c[5])
{
	printf("Inside func():\n");
	printf("sizeof(d) = %d\n", sizeof(d));
	printf("sizeof(i) = %d\n", sizeof(i));
	printf("sizeof(c) = %d\n", sizeof(c));
	printf("%p %p %p\n", d, i, c);
}

int main()
{
	double d_arr[5] = {1.4, 2.5, 3.7, 4.1, 5.9};
	int i_arr[5] = {1, 2, 3, 4, 5};
	char c_arr[5] = {'a', 'b', 'c', 'd', 'e'};
	printf("Inside main():\n");
	printf("sizeof(d_arr) = %d\n", sizeof(d_arr));
	printf("sizeof(i_arr) = %d\n", sizeof(i_arr));
	printf("sizeof(c_arr) = %d\n", sizeof(c_arr));
	printf("%p %p %p\n", d_arr, i_arr, c_arr);
	func(d_arr, i_arr, c_arr);

	return 0;
}


