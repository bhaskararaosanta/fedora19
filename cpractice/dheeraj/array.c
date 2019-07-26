#include<stdio.h>
int main()
{
        double a[10];
	a[0] = 10;
	a[1] = 20;
	a[2] = 30;
	a[3] = 40;
	a[4] = 50;
	printf("%d\n",a[0]);
	printf("%d %d %d %d %d\n",a[5],a[6],a[7],a[8],a[9]);
	printf("%d %d %d %d %d\n",*(a+5),*(a+6),*(a+7),*(a+8),*(a+9));
	printf("%p %p %p %p %p\n",&a[0],&a[1],&a[2],&a[3],&a[4]);
	printf("%p %p %p %p %p\n",a+0,a+1,a+2,a+3,a+4);
	printf("%p\n",a);
	return 0;
}
