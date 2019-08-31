#include <stdio.h>

struct pointer{
	int len;
	char *str;
} *p;

int main()
{
	struct pointer pointvar = {100, "bhaskar"};
	p = &pointvar;

	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %s\n", pointvar.str, p->str);

	++p->len;

	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %s\n", pointvar.str, p->str);
	
	(++p)->len;

	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %c\n", pointvar.str, *p->str);
	printf("length is:%d or %d\n", pointvar.len, p->len);
	printf("string is:%s or %s\n", pointvar.str, p->str);



	return 0;
}
