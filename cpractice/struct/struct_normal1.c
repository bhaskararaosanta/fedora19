#include<stdio.h>

struct student{
	int age;
	char name[30];
	float marks;
};

int main()
{
	struct student stu1, stu2 = {30, "Bhaskar", 85.0};
	printf("Enter student1 age, name and marks:\n");
	scanf("%d%s%f", &stu1.age, stu1.name, &stu1.marks);

	printf("The values entered for student1 and student2 are:\n");
	printf("student1 details are: age=%d\tname=%s\tmarks=%f\n", stu1.age, stu1.name, stu1.marks);
	printf("student2 details are: age=%d\tname=%s\tmarks=%f\n", stu2.age, stu2.name, stu2.marks);

	return 0;
}
	

