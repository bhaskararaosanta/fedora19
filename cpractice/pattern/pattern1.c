#include <stdio.h>

#define	N	5

int main()
{
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < i+1; j++) {
			printf("*");
		}
		printf("\n");
	}

	for(i = 0; i < N; i++) {
		for(j = 0; j < i+1; j++) {
			printf("%d", i+1);
		}
		printf("\n");
	}
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < i+1; j++) {
			printf("%d", j+1);
		}
		printf("\n");
	}
	
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(j < N-i-1)
				printf(" ");
			else
				printf("%d", j+1);
		}
		printf("\n");
	}
	
	return 0;
}
