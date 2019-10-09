#include "chardev.h"

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

ioctl_set_msg(int fd, char *message)
{
	int ret_val;
	ret_val = ioctl(fd, IOCTL_SET_MSG, message);
	if(ret_val < 0)
	{
		printf("ioctl_set_msg failed.\n");
		exit(1);
	}
}

ioctl_get_msg(int fd)
{
	int ret_val;
	char message[100];
	ret_val = ioctl(fd, IOCTL_GET_MSG, message);
	if(ret_val < 0)
	{
		printf("ioctl_get_msg failed.\n");
		exit(1);
	}
	printf("get_msg message is:%s\n", message);
}

ioctl_get_nth_byte(int fd)
{
	int i;
	char c;
	i = 0;
	do
	{
		c = ioctl(fd, IOCTL_GET_NTH_BYTE, i++);
		if(c < 0)
		{
			printf("ioctl_get_nth_byte failed at the %d th byte.\n", i);
			exit(1);
		}
	}while(c != '\0');
	putchar('\n');
}

int main()
{
	int fd, ret_val;
	char *msg = "Message Passed by IOCTL\n";
	fd = open(DEVICE_FILE_NAME, 0)
	if(fd < 0)
	{
		printf("Can't open device file:%s\n", DEVICE_FILE_NAME);
		exit (1);
	}
	
	ioctl_get_nth_byte(fd);
	ioctl_get_msg(fd);
	ioctl_set_msg(fd, msg);

	close(fd);

	return 0;
}
