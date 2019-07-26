#include<stdio.h>

struct book{
	char title[40];
	int number;
} Book1;

union student{
	char name[40];
	int rollno;
} Student1;

int main()
{
	int a, b, c;
	float p, q, r;
	char x, y, z;
	int iarray[20], iarrayextra[20] = {10, 20, 30}, *iarrayptr = (int *)100;
	char carray[20], carrayextra[20] = "bhaskar is good", *carrayptr = "bhaskar is changing";
	struct book *bookptr;
	union student *studentptr;

	bookptr = &Book1;
	studentptr = &Student1;

	printf("size of int:%d\n", sizeof(int));
	printf("size of short and short int:%d\t%d\n", sizeof(short), sizeof(short int));
	printf("size of long and long int:%d\t%d\n", sizeof(long), sizeof(long int));
	printf("size of long long int:%d\n", sizeof(long long), sizeof(long long int));
	printf("\n");

	printf("size of float:%d\n", sizeof(float));
	printf("size of double:%d\n", sizeof(double));
	printf("\n");

	printf("sizeof uninitialized int array:%d\n", sizeof(iarray));
	printf("sizeof initialized int array:%d\n", sizeof(iarrayextra));
	printf("size of pointer to int string:%d\n", sizeof(iarrayptr));
	printf("sizeof uninitialized char array:%d\n", sizeof(carray));
	printf("sizeof initialized char array:%d\n", sizeof(carrayextra));
	printf("size of pointer to char string:%d\n", sizeof(carrayptr));
	printf("\n");

	printf("size of structure book:%d\t%d\n", sizeof(struct book), sizeof(Book1));
	printf("size of pointer to struct book:%d\t%d\n", sizeof(struct book *), sizeof(bookptr));
	printf("\n");

	printf("size of union student:%d\t%d\n", sizeof(union student), sizeof(Student1));
	printf("size of pointer to union student:%d\t%d\n", sizeof(union student *), sizeof(studentptr));
	printf("\n");

	return 0;
}
