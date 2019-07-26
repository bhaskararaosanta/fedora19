#include<stdio.h>

struct point{
	int x;
	int y;
};

struct rect{
	struct point pt1;
	struct point pt2;
};

/* makepoint: make a point from x and y components */
struct point makepoint(int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

int main()
{
	printf("size of point structure:%d\n", sizeof(struct point));
	printf("size of rect structure:%d\n", sizeof(struct rect));
	struct point pt = {320, 200};
	struct rect screen  = {{10, 20}, {30, 40}};
	printf("%d, %d\n", pt.x, pt.y);
	struct point newpt = makepoint(100, 200);
	printf("%d, %d\n", newpt.x, newpt.y);
	printf("%d, %d, %d, %d\n", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);
	return 0;
}


