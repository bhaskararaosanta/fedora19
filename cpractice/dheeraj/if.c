#include<stdio.h>
int main()
{
	long long int a=10000000000000,b=5;
	
	long long int *aptr;
	aptr = &a;
	if(a<20)
	{
		printf("%lld\n",a);
		printf("%p\n",&a);
		printf("%p\n",aptr);
		printf("%p\n",&aptr);



	}
	else
	{
		printf("%d\n",b);
		printf("%d\n",&b);
	}
	return 0;
}
