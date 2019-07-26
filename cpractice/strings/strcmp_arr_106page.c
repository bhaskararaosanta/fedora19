#include<stdio.h>

int strcmp1(char *s, char *t)
{
	int i;
	for(i = 0; s[i] == t[i]; i++)
		if(s[i] == '\0')
			return 0;
	return(s[i] - t[i]);
}

int main()
{
	int x, y, z;
	
	char a[10] = "Deepak", b[10] = "Bhaskar";
	char *sptr = "Bhaskar", *tptr = "Nayana";
	char *sptr_1 = "Bhaskar", *tptr_1 = "Bhaskar";
	x = strcmp1(a, b);
	y = strcmp1(sptr, tptr);
	z = strcmp1(sptr_1, tptr_1);
	printf("Values of x, y and z:\t%d\t%d\t%d\n", x, y, z);

	return 0;
}
