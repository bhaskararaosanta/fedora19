#include<stdio.h>

void static strcpy(char *s, char *t)
{
	int i;
	i = 0;
	while((s[i] = t[i]) != '\0')
		i++;
}

int main()
{
	char a[100] = "Bhaskar is a good boy", b[100];
	char *sptr = "Bhaskar is a good boy", *tptr;
	strcpy(b, a);
	strcpy(tptr, sptr);
	printf("string stored in a:%s\n", a);
	printf("string stored in b:%s\n", b);
	printf("string stored in a:%s\n", sptr);
	printf("string stored in a:%s\n", tptr);

	return 0;
}
