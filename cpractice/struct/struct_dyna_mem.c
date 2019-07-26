#include<stdio.h>
#include<stdlib.h>

struct person{
	int age;
	float weight;
	char name[30];
};

int main()
{
	struct person *ptr;
	int i, n;
	printf("Enter number of persons:");
	scanf("%d", &n);
	ptr = (struct person *)malloc(n * sizeof(struct person));
	for(i = 0; i < n; i++)
	{
		printf("Enter first name and age respectively:");
		scanf("%s%d", (ptr+i)->name, &(ptr+i)->age);
	}
	printf("Displaying information:\n");
	for(i = 0; i < n; i++)
	{
		printf("Enter first name and age respectively:");
		printf("name:%s\tage:%d\n", (ptr+i)->name, (ptr+i)->age);
	}

	return 0;
}
