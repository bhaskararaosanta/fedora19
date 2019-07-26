#include<stdio.h>

int main()
{
	int i;
	struct student{
		int roll_no;
		char name[30];
		int age;
	};

	struct student stud[5];

	for(i = 0; i <= 4; i++)
	{
		printf("Student %d\n", i+1);
		stud[i].roll_no = i + 1;
		printf("Enter name:\n");
		scanf("%s", stud[i].name);
		printf("Enter age:\n");
		scanf("%d", &stud[i].age);
	}
	
	for(i = 0; i <= 4; i++)
	{
		printf("Student roll no %d\n", stud[i].roll_no);
		printf("Enter name:%s\n", stud[i].name);
		printf("Enter age:%d\n", stud[i].age);
	}

	return 0;
}
