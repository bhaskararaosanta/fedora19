#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define MAJOR_NUM       0xFE
#define IOCTL_SET_MGS   _IOW(MAJOR_NUM, 0, char *)
#define IOCTL_GET_MSG   _IOR(MAJOR_NUM, 1, char *)
#define IOCTL_GET_NTH_BYTE      _IOWR(MAJOR_NUM, 2, int)

#define DEVICE_NAME "char_dev"
#define	SUCCESS	0
#define	DEVICE_NAME	"char_dev"
#define	BUF_LEN	80

static int Device_open = 0;
static char Message[BUF_LEN];
static char *Message_Ptr;

static int device_open(struct inode *inodep, struct file *filep)
{
#ifdef DEBUG
	printk(KERN_INFO "device open at address:%p\n", filep);
#endif

	if(Device_open)
		return -EBUSY;

	Device_open++;
	Message_Ptr = Message;
	try_module_get(THIS_MODULE);
	return SUCCESS;
}

static int device_release(struct inode *inodep, struct file *filep)
{
#ifdef DEBUG
	printk(KERN_INFO "device release at inode and file:%p and %p\n", inodep, filep);
#endif

	Device_open--;
	module_put(THIS_MODULE);
	return SUCCESS;
}

static ssize_t device_read(struct file *filep, char __user *buffer, size_t length, loff_t *offset)
{
	int bytes_read = 0;
#ifdef DEBUG
	printk(KERN_INFO "device reading at address:%p and buffer:%d and data length:%d\n", filep, buffer, length);
#endif
	if(*Message_Ptr == 0)
		return 0;
	while(length && *Message_Ptr)
	{
		put_user(*(Message_Ptr++), buffer++);
		length--;
		bytes_read++;
	}

#ifdef DEBUG
	printk(KERN_INFO "Read %d bytes, %d left\n", bytes_read, length);
#endif
	return bytes_read;
}

static ssize_t device_write(struct file *filep, const char __user *buffer, size_t length, loff_t *offset)
{
	int i;
#ifdef DEBUG
	printk(KERN_INFO "device write with file address:%p buffer:%s and buffer length:%d\n", filep, buffer, length);
#endif
	for(i = 0; i < length && i < BUF_LEN; i++)
		get_user(Message[i], buffer+i);
	Message_Ptr = Message;
	return i;
}

int device_ioctl(struct inode *inodep, struct file *filep, unsigned int ioctl_num, long unsigned int ioctl_param)
{
	int i;
	char *temp;
	char ch;
	switch(ioctl_num)
	{
		case IOCTL_SET_MSG:
			temp = (char *)ioctl_param;
			get_user(ch, temp);
			for(i = 0; ch && i < BUF_LEN; i++, temp++)
				get_user(ch, temp);

			device_write(filep, (char *)ioctl_param, i, 0);
			break;
		
		case IOCTL_GET_MSG:
			i = device_read(filep, (char *)ioctl_param, 99, 0)
			put_user('\0', (char *)ioctl_param + i);
			break;

		case IOCTL_GET_NTH_BYTE:
			return Message[ioctl_param];
			break;
	}

	return SUCCESS;
}

struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.unlocked_ioctl = device_ioctl,
	.open = device_open,
	.release = device_release
};

int hello_init(void)
{
	int ret_val;
	ret_val = register_chrdev(MAJOR_NUM, DEVICE_NAME, &fops);
	if(ret_val < 0)
	{
		printk(KERN_INFO "Registering of char device failed with return value:%d\n", ret_val);
		return ret_val;
	}
	printk(KERN_INFO "Device registered with major number:%d\n", MAJOR_NUM);
	printk(KERN_INFO "create device file manually by using: mknod devicename c MAJOR_NUM minor_num.\n");

	return 0;
}

void hello_exit(void)
{
	int ret;
	unregister_chrdev(MAJOR_NUM, DEVICE_NAME);

	/*if(ret < 0)
		printk(KERN_INFO "Error in unregistering device\n");
	*/
	printk(KERN_INFO "module unloaded successfully.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("Bhaskar");
MODULE_LICENSE("BSD/GPL");
MODULE_VERSION("0.1");
MODULE_SUPPORTED_DEVICE("Its a dummy driver");
