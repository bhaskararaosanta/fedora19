#include<stdio.h>

char *month_name(int n)
{
	int i = 0;
	char *name[] = {
		"Illegal month",
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"Jun",
		"Jul",
		"Aug",
		"Sep",
		"Oct",
		"Nov",
		"Dec"
	};
	for(i = 0; i <= 12; i++)
	{
		printf("pointer address of name array:%p\n", name[i]);
		printf("address of name array stored:%p\n", &name[i]);
	}

	return (n < 1 || n > 12) ? name[0] : name[n];
}

int main()
{
	int i = 0;
	char *month[13];
	for(i = 0; i <= 12; i++)
	{
		printf("pointer address of month array:%p\n", month[i]);
		printf("address of month array stored:%p\n", &month[i]);
	}
	for(i = 0; i <= 12; i++)
	{
		month[i] = month_name(i);
	}
	for(i = 0; i <= 12; i++)
	{
		printf("month name is:%s\n", month[i]);
	}
	return 0;
}
