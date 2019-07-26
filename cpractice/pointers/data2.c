#include<stdio.h>

int main()
{
	char *p[5];
	int i;
	p[0] = "DATA";
	p[1] = "LOGIC";
	p[2] = "MICROPROCESSOR";
	p[3] = "COMPUTER";
	p[4] = "DISK";

	for(i = 0; i < 5; i++)
	{
		printf("%s\n", p[i]);
	}

	return 0;
}
