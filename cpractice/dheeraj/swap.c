#include<stdio.h>
#include<stdio.h>
void swap(int *x,int *y)
{
	printf("%d %d\n",*x,*y);
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	printf("%d %d\n",*x,*y);
}

/*void swap(int x,int y)
{
	printf("%d %d\n",x,y);
	int temp;
	temp = x;
	x = y;
	y = temp;
	printf("%d %d\n",x,y);
}*/

int main()
{
	int a = 10,b = 20;
	printf("%d %d\n",a,b);
	swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}
