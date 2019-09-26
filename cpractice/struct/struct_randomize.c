#include <stdio.h>

struct student{
	char name[21];
	int age;
	char namenew[21];
	char b;
	int a;
	char name1[21];
	int age1;
	char namenew1[21];
	char b1;
	int a1;
} __randomize_layout;  /* no change in memory allocation may be some source file issue */

int main()
{
	printf("size of structure:%d\n", sizeof(struct student));

	return 0;
}
