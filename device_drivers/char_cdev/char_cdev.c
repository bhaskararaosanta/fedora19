#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/semaphore.h>
#include <linux/uaccess.h>

struct fake_device {
	char data[100];
	struct semaphore sem;
} virtual_device;

/* it is recommened to define variables as global space because kernel space stack is very limited */
/* struct cdev {
        struct kobject kobj;
        struct module *owner;
        const struct file_operations *ops;
        struct list_head list;
        dev_t dev;
        unsigned int count;
} __randomize_layout; */
struct cdev *mycdev;

int major_number;
int ret;

dev_t dev_num;

#define	DEVICE_NAME	"ISMTestDevice"

static int device_open(struct inode *inodep, struct file *filep)
{
	/* extern int __must_check down_interruptible(struct semaphore *sem); */
	if(down_interruptible(&virtual_device.sem) != 0) {
		printk(KERN_ALERT "could not lock device during open\n");
		return -1;
	}
	printk(KERN_INFO "device_open function called.\n");
	return 0;
}

static ssize_t device_read(struct file *filep, char *ubuf, size_t count, loff_t *offset)
{
	printk(KERN_INFO "reading from device\n");
	ret = copy_to_user(ubuf, virtual_device.data, count);
	return ret;
}

static ssize_t device_write(struct file *filep, const char *ubuf, size_t count, loff_t *offset)
{
	printk(KERN_INFO "writing to device\n");
	ret = copy_from_user(virtual_device.data, ubuf, count);
	return ret;
}

static int device_close(struct inode *inodep, struct file *filep)
{
	/* extern void up(struct semaphore *sem); */
	up(&virtual_device.sem);
	printk(KERN_INFO "close device.\n");
	return 0;
}


struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = device_open,
	.release = device_close,
	.write = device_write,
	.read = device_read
};


static int hello_init(void)
{
	/* step - 1: registering device with the system */
	ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
	if(ret < 0) {
		printk(KERN_ALERT "ISMTestDevice: failed to allocate a major number\n");
		return ret;
	}
	major_number = MAJOR(dev_num);   // extract  major number using MAJOR macro
	printk(KERN_INFO "major number is:%d\n", major_number);
	printk(KERN_INFO "\t use \"mknod /dev/%s c %d 0\" for device file\n", DEVICE_NAME, major_number);
	
	/* step - 2 */
	/* struct cdev *cdev_alloc(void); */
	mycdev = cdev_alloc(); // create our cdev structure and initialized our cdev
	mycdev->ops = &fops;   // struct file_operations
	mycdev->owner = THIS_MODULE;
	/* int cdev_add(struct cdev *, dev_t, unsigned); */
	ret = cdev_add(mycdev, dev_num, 1);  // adding cdev structure to the kernel
	if(ret < 0) {
		printk(KERN_ALERT "unable to add cdev to kernel\n");
		return ret;
	}

	/* initializing the semaphore */
	/* static inline void sema_init(struct semaphore *sem, int val)
	{
        static struct lock_class_key __key;
        *sem = (struct semaphore) __SEMAPHORE_INITIALIZER(*sem, val);
        lockdep_init_map(&sem->lock.dep_map, "semaphore->lock", &__key, 0);
	} */
	sema_init(&virtual_device.sem, 1);

	return 0;
}

static void hello_exit(void)
{
	/* void cdev_del(struct cdev *); */
	cdev_del(mycdev);
	unregister_chrdev_region(dev_num, 1);
	printk(KERN_INFO "Module unloaded successfully.\n");
}

module_init(hello_init);
module_exit(hello_exit);
