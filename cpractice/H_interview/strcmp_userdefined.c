#include <stdio.h>

int strcmp(const char *a, const char *b)
{
	while(*a)
	{
		// charcters differ or end of second string reached
		if(*a != *b)
			break;

		// move to next pair of characters
		a++;
		b++;
	}
	// return the ASCII difference after converting char * to unsigned char *
	//return *(const unsigned char *)a - *(const unsigned char *)b;
	return *a - *b;
}


int main()
{
	char *y = "Techie";
	char *x = "Techie";

	int ret = strcmp(x, y);

	if(ret > 0)
		printf("%s\n", "x is greater than y.");
	else if(ret < 0)
		printf("%s\n", "x is less than y");
	else
		printf("%s\n", "x is equal to y");

	return 0;
}
