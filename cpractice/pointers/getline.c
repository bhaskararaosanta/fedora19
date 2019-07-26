#include<stdio.h>

char *getline1(void);

char templine[100];

int main()
{
	int j;
	char *line;

	line = getline1();
	printf("line read is:%s\n", line);
	for(j = 0; j < 100; j++)
		putchar(*line++);
	return 0;
}

char *getline1(void)
{
	int i = 0;
	char c;
	while((c = getchar()) != EOF && c != '\n')
		templine[i++] =c;
	if(c == '\n')
		templine[i++] = c;
	templine[i] = '\0';
	return templine;
}
		

