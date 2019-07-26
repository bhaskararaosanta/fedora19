#include<stdio.h>

char GRADE(int m)
{
	return ('A'+(4-m/20)+(m==100));
}

int POINTS(char g)
{
	return (2 * (70-g));
}

int main()
{
	int n, m, i, p = 0;
	char v;
	float s = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &m);
		v = GRADE(m);
		if(v != 'E') p++;
		s += POINTS(v);
	}
	s = s/n;
	((p == 0) && (s >= 5))?	printf("yes\n"): printf("no\n");
       return 0;
}       
