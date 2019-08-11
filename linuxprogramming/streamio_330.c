#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>

#define	ITERATIONS	9000

int main()
{
	int number;
	char writestring[100];
	int counter;
	int size;
	FILE *output;

	printf("Please enter a number:");
	scanf("%d", &number);

	number /= 2;

	printf("Writing %d copied of %d to a file.\n", ITERATIONS, number);
	output = fopen("testfile", "wb");
	if(!output)
	{
		perror("Can't open output file");
		exit(EXIT_FAILURE);
	}

	sprintf(writestring, "%d", number);
	size = strlen(writestring);

	for(counter = 0; counter < ITERATIONS; counter++)
	{
		fwrite(writestring, size, 1, output);
	}
	fclose(output);

	return 0;
}
