#include<stdio.h>
int main()
{
	int a=10,b=5;
	int *aptr,**aaptr;
	aptr = &a;
	aaptr=&aptr;
	printf("%d %d %d \n",a,*aptr,**aaptr);
	printf("adress of a %p\n",&a);
	printf("memory adress stored in aptr %p %p\n",aptr,*aaptr);
	printf("memory adress where aptr is stored %p %p\n",&aptr,&aaptr);
	return 0;
}
