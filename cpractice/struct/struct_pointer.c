#include <stdio.h>
struct pointer;

struct student{
	int age;
	char name[30];
};

struct pointer{
	int len;
	char *str;
	struct student stu;
} *p;

int main()
{
	struct pointer pointvar = {100, "bhaskar", {20, "newyork"}};
	p = &pointvar;

	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %s\n", pointvar.str, p->str);

	printf("student age is:%d or %d\n", pointvar.stu.age, p->stu.age);
	printf("student name:%s or %s\n", pointvar.stu.name, p->stu.name);
	
	++p->len;

	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %s\n", pointvar.str, p->str);
	
/*	(++p)->len;

	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %c\n", pointvar.str, *p->str);
	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %s\n", pointvar.str, p->str);
*/


	return 0;
}
