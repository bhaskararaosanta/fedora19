#include<stdio.h>
int strlen1(char *s)
{
	int i = 0;
	while(*s++!='\0')
	i++;
	printf("%d\n",i);
}
int main()
{
	char name[30]="dheeraj";
	int c;
	c = strlen1(name);
	printf("%d\n",c);
	return 0;

}
