#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

#define	ITERATIONS	9000

int main()
{
	int number;
	char writestring[100];
	int counter;
	int size;
	int fd;

	printf("Please enter a number:");
	scanf("%d", &number);

	number /= 2;

	printf("Writing %d copied of %d to a file.\n", ITERATIONS, number);
	fd = open("testfile", O_CREAT | O_TRUNC, 0666);
	if(!fd)
	{
		perror("Can't open output file");
		exit(EXIT_FAILURE);
	}

	sprintf(writestring, "%d", number);
	size = strlen(writestring);

	for(counter = 0; counter < ITERATIONS; counter++)
	{
		write(fd, writestring, size);
	}
	close(fd);

	return 0;
}
