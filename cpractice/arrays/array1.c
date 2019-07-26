#include<stdio.h>

int main()
{
	//int i;
	int iarray[6];
	char carray[6];
	float farray[6];
	double darray[6];

	printf("Printing all array values before initialization:\n");
	for(int i = 0; i < 6; i++)
	{
		printf("values in int array of iarray[%d] is:%d\n", i, iarray[i]);
		printf("values in char array of carray[%d] is:%c\n", i, carray[i]);
		printf("values in float array of farray[%d] is:%f\n", i, farray[i]);
		printf("values in double array of darray[%d] is:%lf\n", i, darray[i]);
		printf("size of array of iarray[%d] is:%d\n", i, sizeof(iarray));
		printf("size of char array of carray[%d] is:%d\n", i, sizeof(carray));
		printf("size of float array of farray[%d] is:%d\n", i, sizeof(farray));
		printf("size of double array of darray[%d] is:%d\n", i, sizeof(darray));
	}
	return 0;
}
