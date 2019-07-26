#include<stdio.h>

void static strcpy1(char *s, char *t)
{
	while(*s++ = *t++);
}

int main()
{
	char a[100] = "Bhaskar is a good boy", b[100];
	char *sptr = "Bhaskar is a good boy", *tptr;
	strcpy1(b, a);
	strcpy1(tptr, sptr);
	printf("string stored in a:%s\n", a);
	printf("string stored in b:%s\n", b);
	printf("string stored in a:%s\n", sptr);
	printf("string stored in a:%s\n", tptr);

	return 0;
}
