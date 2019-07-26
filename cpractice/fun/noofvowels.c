#include<stdio.h>
#include<ctype.h>

int ISVOWEL(char v)
{
	switch(toupper(v))
	{
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U': return 1;
		default: return 0;
	}
}

int NV(char a[])
{
	int n = 0, i;
	for(i = 0; a[i] != '\0'; i++)
		if(ISVOWEL(a[i]))
			n++;
	return n;
}


int main()
{
	char x[20];
	scanf("%s", x);
	printf("%d\n", NV(x));
	return 0;
}
