#include<stdio.h>

char GRADE(int m)
{
	return ('A'+(4-m/20)+(m==100));
}

int POINTS(char g)
{
	return (2 * (70-g));
}

int main()
{
	int n, p;
	char v;
	scanf("%d", &n);
	v = GRADE(n);
	p = POINTS(v);
	printf("%d\t%c\t%d\n", n, v, p);
       return 0;
}       
