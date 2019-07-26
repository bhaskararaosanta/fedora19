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

int main()
{
	char x;
	scanf("%c", &x);
	(ISVOWEL(x))? printf("yes\n"): printf("no\n");
	return 0;
}
