#include<stdio.h>

/*int strlen1(char a[20])
{
	int i = 0, n = 0;
	while(a[i++] != '\0')
		n++;
	return n;
}*/

int strlen1(char *s)
{
	char *p = s;
	while(*s)
		s++;
	return s - p;
}

int main()
{
	char *a = "Bhaskar";
	char b[20] = "deepak";
	char c[20] = {'b','h','a','s','k','a','r'};
	printf("string length of a:%d\n", strlen1(a));
	printf("string length of name:%d\n", strlen1("Nayana"));
	printf("string length of b:%d\n", strlen1(b));
	printf("string length of b:%d\n", strlen1(c));

	return 0;
}
