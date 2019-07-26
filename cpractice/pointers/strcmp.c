#include<stdio.h>

/*int strcmp(char *s, char *t)
{
	int i;
	for(i = 0; s[i] == t[i]; i++)
		if(s[i] == '\0')
			return 0;
	return (s[i]-t[i]);
} */

int strcmp(const char *s, const char *t)
{
	int i;
	for(; *s == *t; s++, t++)
		if(*s == '\0')
			return 0;
	return (*s - *t);
}

int main()
{
	int c;
	char a[20], b[20];
	printf("Enter two strings to compare:");
	scanf("%s%s", a, b);
	c = strcmp(a, b);
	printf("Value of c:%d\n", c);
	return 0;
}
