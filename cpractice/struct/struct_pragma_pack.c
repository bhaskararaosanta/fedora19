#include<stdio.h>

struct student{
	int a;
	char c;
	double d;
}__attribute__((packed));

//without __attribute__((packed)) the sizeof structure will show 16bytes because structure padding

int main()
{
	struct student stu;
	printf("size of structure student:%d\n", sizeof(stu));
	return 0;
}
