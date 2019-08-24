/* chardev.c: Creates a read-only char device driver that says
 * how many times you have read from the device file */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>	/* for put user */

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

#define	SUCCESS 0
#define	DRIVER_NAME "chardev"	/* driver name as appears in /proc/devices */
#define	BUF_LEN	80		/* Max length of the message from the driver */
#define DEVICE_FILENAME	"TestDevice"	/* device file name to interact with driver */	

static int major_num;		/* Major number to be assigned to our device driver */
static int dev_open = 0;	/* Is devide open? used to prevent multiple access to driver */
static char msg[BUF_LEN];	/* the message the driver will give when asked */
static char *msg_ptr;

static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.release = device_release
};

int init_module(void)
{
	major_num = register_chrdev(0, DRIVER_NAME, &fops);
	if(major_num < 0)
	{
		printk(KERN_ALERT "Registering char driver failed with %d\n", major_num);
		return major_num;
	}
	
	printk(KERN_INFO "Major number assigned for the driver is:%d\n", major_num);
	printk(KERN_INFO "Now create a device file using the driver major number\n");
	printk(KERN_INFO "'mknod /dev/%s c %d 0' \n", DEVICE_FILENAME, major_num);
	printk(KERN_INFO "try different minor numbers. Try to cat and echo to device file created.\n");

	return 0;
}

void cleanup_module(void)
{
	/* unregister the driver */
	unregister_chrdev(major_num, DRIVER_NAME);
	/* int ret = unregister_chrdev(major_num, DRIVER_NAME);
	if(ret < 0)
	{
		printk(KERN_ALERT "Error in unregister the driver\n", ret);
	} */
}

/* functions to be called when a process tries to open the device files using "cat /dev/TestDevice" */

static int device_open(struct inode *inodep, struct file *filep)
{
	static int counter = 0;
	if(dev_open)
		return -EBUSY;
	dev_open++;
	sprintf(msg, "I already told you %d times hello world!\n", counter++);
	msg_ptr = msg;
	try_module_get(THIS_MODULE);
	
	return SUCCESS;
}

static int device_release(struct inode *inodep, struct file *filep)
{
	dev_open--;	/* we are now ready for our next caller */
	/*decrement the usage count, or else once you opened the file, you'll
	 * never get rid of the module */
	
	module_put(THIS_MODULE);
	return 0;
}

static ssize_t device_read(struct file *filep, /* see include linux/fs.h */
				char *buffer,  /* buffer to fill with data */
				size_t length, /* length of the buffer */
				loff_t *offset)
{
	int bytes_read = 0;
	if(*msg_ptr == 0)
		return 0;
	while(length && *msg_ptr)
	{
		/* the buffer is in user data segment, not the kernel segment, so "*" assignment
		 * won't work. We have to use put_user which copies data from the kernel data
		 * segment to the user data segment */
		put_user(*(msg_ptr++), buffer++);
		length--;
		bytes_read++;
	}
	/* most read functions return the number of bytes put into the buffer */
	return bytes_read;
}

static ssize_t device_write(struct file *filep, const char *buff, size_t len, loff_t *off)
{
	printk(KERN_ALERT "Sorry, Write function is not implemented in this driver.n");
	return -EINVAL;
}
	



