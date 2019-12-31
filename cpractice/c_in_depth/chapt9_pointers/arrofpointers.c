#include <stdio.h>

int main()
{
	char *name[] = {"Illegal month", "january", "February", "March"};
	int i;
	for(i = 0; i < 4; i++) {
		printf("Address contained in name[%d] = %p\n", i, name[i]);
	}
	printf("\n");

	printf("Address pointed by name array:%p\n\n", name);
	for(i = 0; i < 4; i++) {
		printf("Address of name[%d] = %p\n", i, &name[i]);
	}
	printf("\n");

	for(i = 0; i < 4; i++) {
		printf("Data pointed by name[%d] = %s\n", i, name[i]);
	}

	return 0;
}
