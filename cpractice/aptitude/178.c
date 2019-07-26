#include<stdio.h>

char *someFun()
{
	char *temp = "string constant";
	//char temp[] = "string constant";  //we can't use this statement
	return temp;
}

int main()
{
	puts(someFun());
	return 0;
}
