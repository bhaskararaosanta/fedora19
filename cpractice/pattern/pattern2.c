#include <stdio.h>

#define	N	5

int main()
{
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j <= i; j++) {
			printf("%d", j+1);
		}
		printf("\n");
	}

	for(i = 0; i < N; i++) {
		for(j = i; j < N; j++) {
			printf("%d", N-j);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}


