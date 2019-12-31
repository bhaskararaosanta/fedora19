#include <stdio.h>

int main()
{
	union {
		struct st {
			char a;
			char b;
		} data;

		struct stextra {
			int i;
			int j;
		} value;
	} u = {{14, 1}, {15, 1}};

	union u *it;
	it = &u;
	printf("%d\t%d\n", it->value.i, it->value.j);

	return 0;
}

