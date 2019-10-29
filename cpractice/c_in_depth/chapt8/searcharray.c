#include <stdio.h>

#define	N	6

int search(int localarr[], int num, int searchval)
{
	int i = 0;
	for(i = 0; i < N; i++) {
		if(searchval == localarr[i])
			return 1;
	}
	return 0;
}

int main()
{
	int i, j, arr[N] = {10, 20, 30, 40, 50, 60}, searchitem = 31;
	i  = search(arr, N, searchitem);
	i ? printf("found element in array\n"): printf("not found\n");

	return 0;
}
