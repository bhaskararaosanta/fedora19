#include<stdio.h>

struct Student{
	char name[18];
	int rollno;
};

int main()
{
	int i, j;
	printf("size of student structure:%d\n", sizeof(struct Student));

	struct Student array[5];
	for(i = 0; i < 5; i++)
	{
		printf("Enter structure array elements:\n");
		printf("Enter %d student name:", i);
		scanf("%s", array[i].name);
		printf("Take %d student rollno from variable i:", i);
		array[i].rollno = i;
		printf("\n");
	}
	
	for(i = 0; i < 5; i++)
	{
		printf("Printing structure array elements:\n");
		printf("Printing %d student name:", i);
		printf("%s\t", array[i].name);
		printf("Printing %d student rollno:", i);
		printf("%d\n", array[i].rollno);
		printf("Address %d student name:", i);
		printf("%p\t", &array[i].name);
		printf("Address %d student rollno:", i);
		printf("%p\n", &array[i].rollno);
	}

	printf("size of student structure:%d\n", sizeof(struct Student));

	printf("size of student structure:%d\n", sizeof(array));

	return 0;

}

