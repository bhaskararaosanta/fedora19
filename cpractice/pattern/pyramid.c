#include <stdio.h>

#define	N	5

int main()
{
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if((i == 0) && (j >= 0)) {
				printf("*");
			}
			else if((i == N-1) && (j >= 0)) {
				printf("*");
			}
			else if((j == 0) && (i >= 0)) {
				printf("*");
			}
			else if((j == N-1) && (i >= 0)) {
				printf("*");
			}
		}
		printf("\n");
	}
	printf("\n");

	for(i = 0; i < N; i++) {
		for(j = 0; j < i+1; j++) {
			printf("*");
		}
		printf("\n");
	}

	printf("\n");

	for(i = 0; i < N; i++) {
		for(j = 0; j < N-i; j++) {
			printf("*");
		}
		printf("\n");
	}
	
	printf("\n");

	return 0;
}

