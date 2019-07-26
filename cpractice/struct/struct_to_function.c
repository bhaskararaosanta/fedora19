#include<stdio.h>

struct student{
	char name[10];
	int roll;
};

void show(struct student );

int main()
{
	struct student std;
	printf("Enter student record\n");
	printf("Student name:");
	scanf("%s", std.name);
	printf("Enter student roll number:");
	scanf("%d", &std.roll);
	show(std);
}

void show(struct student st)
{
	printf("Displaying student record\n");
	printf("Student name:%s\n", st.name);
	printf("Student roll number:%d\n", st.roll);
}



