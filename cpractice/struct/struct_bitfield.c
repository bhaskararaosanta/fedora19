#include<stdio.h>

struct dayofyear{
	unsigned int d;
	unsigned int m;
	unsigned int y;
};

struct dayofyearbits{
	unsigned int d:5;
	unsigned int m:4;
	//unsigned int dummy:23;
	unsigned int y;
};

int main()
{
	struct dayofyear day1 = {31, 10, 1983};
	printf("size of dayofyear:%d\n", sizeof(day1));
	printf("printed date is:%d/%d/%d\n", day1.d, day1.m, day1.y);
	struct dayofyearbits day2 = {31, 12, 2018};
	printf("size of dayofyearbits:%d\n", sizeof(day2));
	printf("printed date is:%d/%d/%d\n", day2.d, day2.m, day2.y);
	return 0;
}

