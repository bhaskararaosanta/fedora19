#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define DEVICE "/dev/ISMTestDevice"

int main()
{
	int i, fd;
	char ch, wbuf[100], rbuf[100];

	fd = open(DEVICE, O_RDWR);

	if(fd < 0) {
		printf("Device file opening error.\n");
		exit(1);
	}
	printf("r = read from device\nw = write to device\nenter command:");
	scanf("%c", &ch);

	switch(ch)
	{
		case 'w': 
			printf("enter data less than 100 characters:");
			//scanf("%*[^\n]");
			scanf(" %[^\n]", wbuf); 
			write(fd, wbuf, sizeof(wbuf));
			break;

		case 'r': 
			read(fd, rbuf, sizeof(wbuf));
			printf("data read from device:%s\n", rbuf);
			sleep(20);
			break;
	}

	return 0;
}
