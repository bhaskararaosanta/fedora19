#include<stdio.h>

union student{
	int a;
	char b;
	float c;
};

int main()
{
	union student stu;
	printf("Union stu size:%d\n", sizeof(stu));
	printf("Union stu size:%d\n", sizeof(union student));
	stu.a = 100;
	printf("value of union member a:%d\n", stu.a);
	printf("Address of union member a:%p\n", &stu.a);
	printf("Address of union member b:%p\n", &stu.b);
	printf("value of union member b:%d\n", stu.b);
	printf("value of union member c:%f\n", stu.c);
	stu.b = 50;
	printf("value of union member a:%d\n", stu.a);
	printf("value of union member b:%d\n", stu.b);
	printf("value of union member c:%f\n", stu.c);
	printf("Address of union member a:%p\n", &stu.a);
	printf("Address of union member b:%p\n", &stu.b);
	return 0;
}
