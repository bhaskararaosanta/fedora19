#include<stdio.h>

int main()
{
	struct dob{
		int day;
		int month;
		int year;
	};

	struct student{
		struct dob d;
		int rollno;
		char name[25];
		int totalmark;
	}stud[25];
	int n,i;
	printf("Enter total number of students\n\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter details of %d-th student\n\n",i+1);
		printf("\nName:\n");
		scanf("%s",&stud[i].name);
		printf("\nRoll number:\n");
		scanf("%d",&stud[i].rollno);
		printf("\nTotal mark:\n");
		scanf("%d",&stud[i].totalmark);
		printf("\nDate of birth (Format:01 06 2010):\n");
		scanf("%d%d%d",&stud[i].d.day,&stud[i].d.month,&stud[i].d.year);
	}
	printf("STUDENTS DETAILS:\n");
	for(i=0;i<n;i++)
	{
		printf("\n\nRoll number:%d\n\n",stud[i].rollno);
		printf("Name:%s\n\n",stud[i].name);
		printf("Totel mark:%d\n\n",stud[i].totalmark);
		printf("Date of birth:%d / %d / %d \n\n",stud[i].d.day,stud[i].d.month,stud[i].d.year);
	}
	return 0;
}
