#include <stdio.h>

#define	M	3
#define	N	4

int main()
{
	int i, j, arr[M][N] = {{1, 2, 3, 4}, {10, 20, 30, 40}, {100, 200, 300, 400}};
	int (*ptr)[4];
	ptr = arr;

	printf("Address of 0th row in array:%p\n", arr+0);
	printf("Address of 1st row in array:%p\n", arr+1);
	printf("Address of 2nd row in array:%p\n", arr+2);

	printf("Value of ptr and its holding 0th row address:%p\n", ptr);
	ptr++;
	printf("Value of ptr after increment and it will point 1st row address:%p\n", ptr);
	ptr++;
	printf("Value of ptr after increment and it will point 2nd row address:%p\n", ptr);

	printf("\n");
	printf("Address of 0th row 0th element:%p\n", *(arr+0)+0);
	printf("Address of 0th row 1st element:%p\n", *(arr+0)+1);
	printf("Address of 0th row 2nd element:%p\n", *(arr+0)+2);
	printf("Address of 0th row 3rd element:%p\n", *(arr+0)+3);
	printf("Address of 1st row 0th element:%p\n", *(arr+1)+0);
	printf("Address of 1st row 1st element:%p\n", *(arr+1)+1);
	printf("Address of 1st row 2nd element:%p\n", *(arr+1)+2);
	printf("Address of 1st row 3rd element:%p\n", *(arr+1)+3);
	printf("Address of 2nd row 0th element:%p\n", *(arr+2)+0);
	printf("Address of 2nd row 1st element:%p\n", *(arr+2)+1);
	printf("Address of 2nd row 2nd element:%p\n", *(arr+2)+2);
	printf("Address of 2nd row 3rd element:%p\n", *(arr+2)+3);
	printf("\n");
	
	printf("Value of 0th row 0th element:%3d\n", *(*(arr+0)+0));
	printf("Value of 0th row 1st element:%3d\n", *(*(arr+0)+1));
	printf("Value of 0th row 2nd element:%3d\n", *(*(arr+0)+2));
	printf("Value of 0th row 3rd element:%3d\n", *(*(arr+0)+3));
	printf("Value of 1st row 0th element:%3d\n", *(*(arr+1)+0));
	printf("Value of 1st row 1st element:%3d\n", *(*(arr+1)+1));
	printf("Value of 1st row 2nd element:%3d\n", *(*(arr+1)+2));
	printf("Value of 1st row 3rd element:%3d\n", *(*(arr+1)+3));
	printf("Value of 2nd row 0th element:%3d\n", *(*(arr+2)+0));
	printf("Value of 2nd row 1st element:%3d\n", *(*(arr+2)+1));
	printf("Value of 2nd row 2nd element:%3d\n", *(*(arr+2)+2));
	printf("Value of 2nd row 3rd element:%3d\n", *(*(arr+2)+3));

	return 0;
}

