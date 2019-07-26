#include<stdio.h>
#include<string.h>
#pragma	pack(1)
struct Book{
	//char name[30];
	int accno;
	char name[30];
}array[20];


int main()
{
	int i, j;
	for(i = 0; i < 20; i++)
	{
		strcpy(array[i].name, "hello");
		array[i].accno = i+100;
	}
	printf("sizeof struct array is:%d\t or %d\n", sizeof(struct Book), sizeof(array));
	for(i = 0; i < 20; i++)
	{
		printf("memory at name field stored:%p\t%s\t", &array[i].name, array[i].name);
		printf("memory at accno field stored:%p\t%d\n", &array[i].accno, array[i].accno);
	}

	return 0;
}

