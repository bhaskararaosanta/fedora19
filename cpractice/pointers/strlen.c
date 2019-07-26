#include<stdio.h>

//int strlenfun(const char *);
int strlenfun(char *);

int main()
{
	char a[30] = "Bhaskar is good";
	int c;
	c = strlenfun(a);

	printf("string length is :%d\n", c);
	return 0;
}

int strlenfun(char *s)
{
	int i = 10;
	char *p = s;
	int *q = &i;
	int *r = q;
	printf("address contained in both p and s:%p\t%p\n", p, s);
	printf("address of both p and s:%p\t%p\n", &p, &s);
	printf("address contained in both p and s:%p\t%p\n", q, r);
	printf("address of both p and s:%p\t%p\n", &q, &r);
	while(*p != '\0')
	{
		p++;
		q++;
		printf("address contained in both p and s:%p\t%p\n", p, s);
		printf("address contained in both p and s:%p\t%p\n", q, r);
		printf("Ascii value of character:%d\n", *p);
	}
	return p-s;
}

/* int strlenfun(const char *s)
{
	int i = 0;
	while(*s != '\0')
	{
		i++;
		s++;
		printf("Ascii value of character:%d\n", *s);
	}
	return i;
} */

