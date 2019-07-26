#include<stdio.h>

int main()
{
	char a[20] = "Bhaskar";
	char *ptr = "Naya";

	a[0] = 'N';
//	a++; we can't modify the base location of array and it will always point to same storage
//	ptr[0] = 'B'; //ptr is pointing to string constant and which can't be modified but ptr can modified to point other location
	ptr = a;
	printf("%s\n", a);
	printf("%s\n", ptr);

	return 0;
}
