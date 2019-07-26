#include<stdio.h>
#include<string.h>

int main()
{
	char *s, *t = "hello bhaskar";
//	*t = 'g';	/* we can't modify string constant as indicated above */
	strcpy(s,t);
	printf("copied string:%s\n", s);
	return 0;
}
