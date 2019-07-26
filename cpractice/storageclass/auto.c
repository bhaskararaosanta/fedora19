#include<stdio.h>

void fun(void)
{
	auto int i = 3;
	int j = 10;
	printf("i value:%d\n", i);
	printf("j value:%d\n", j);
	printf("i memory location:%p\n", &i);
	printf("j memory location:%p\n", &j);
}

int main()
{
	fun();
	int a = 10;
	int b = 20;
	printf("a value:%d\n", a);
	printf("b value:%d\n", b);
	printf("a memory location:%p\n", &a);
	printf("b memory location:%p\n", &b);
	{
		printf("a value:%d\n", a);
		printf("a value:%d\n", b);
	printf("a memory location:%p\n", &a);
	printf("b memory location:%p\n", &b);
		{
			printf("a value:%d\n", a);
			printf("a value:%d\n", b);
	printf("a memory location:%p\n", &a);
	printf("b memory location:%p\n", &b);
			{
				printf("a value:%d\n", a);
				printf("a value:%d\n", b);
	printf("a memory location:%p\n", &a);
	printf("b memory location:%p\n", &b);
			}
			printf("a value:%d\n", a);
			printf("a value:%d\n", b);
			printf("a memory location:%p\n", &a);
			printf("b memory location:%p\n", &b);
		}
	}
	return 0;
}
