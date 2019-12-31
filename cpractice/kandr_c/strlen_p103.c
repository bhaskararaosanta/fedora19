#include <stdio.h>
#include <string.h>

int strlen1(char a[])
{
	int i;
	for(i = 0; a[i] != '\0'; i++)
		;
	return i;
}

int strlen2(char *s)
{
	char *p = s;
	while(*p != '\0') {
		p++;
	}
	return p - s;
}

int strlen3(char *p)
{
	char i = 0;
	while(*p != '\0') {
		p++;
		i++;
	}
	return i;
}

int strlen4(char *s)
{
	int n;
	for(n = 0; *s != '\0'; s++) {
		n++;
	}
	return n;
}

int main()
{
	//char str[30] = "Embedded is good topic";
	char *str = "Embedded is good topic";
	printf("string length of str:%d\n", strlen1(str));
	printf("string length of str:%d\n", strlen2(str));
	printf("string length of str:%d\n", strlen3(str));
	printf("string length of str:%d\n", strlen4(str));
	printf("string length of str:%d\n", strlen(str));
	printf("string length of str:%d\n", strlen1("Embedded is good topic"));
	printf("string length of str:%d\n", strlen2("Embedded is good topic"));
	printf("string length of str:%d\n", strlen3("Embedded is good topic"));
	printf("string length of str:%d\n", strlen4("Embedded is good topic"));
	printf("string length of str:%d\n", strlen("Embedded is good topic"));

	return 0;
}
