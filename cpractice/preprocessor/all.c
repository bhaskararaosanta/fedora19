#include<stdio.h>
#define message_for(a,b)\
	printf(#a " and " #b ":smply easy learning\n")

#ifndef MESSAGE
#define MESSAGE "\nYour wish\n.....................\n"
#endif

int main()
{
	printf("File:%s\n", __FILE__);
	printf("Time:%s\n", __TIME__);
	printf("Line:%d\n", __LINE__);
	printf("Vers:%d\n", __STDC__);

	printf(MESSAGE);
	message_for(Tutorial, Point);

	return 0;
}
