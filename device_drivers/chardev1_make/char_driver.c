#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

MODULE_AUTHOR("Bhaskar");
MODULE_LICENSE("GPL/BSD");
MODULE_VERSION("1.0");
MODULE_SUPPORTED_DEVICE("Dummy driver");

int myclose(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Close function called.\n");
	return 0;
}

int myopen(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Open function called.\n");
	return 0;
}

ssize_t myread(struct file *filep, char *ubuf, size_t length, loff_t *offset)
{
	printk(KERN_INFO "Read function called.\n");
	return 0;
}

ssize_t mywrite(struct file *filep, const char *ubuf, size_t length, loff_t *offset)
{
	printk(KERN_INFO "Write function called.\n");
	return 0;
}

struct file_operations fops = {
	.open = myopen,
	.read = myread,
	.write = mywrite,
	.release = myclose
};

int major_num;

static int hello_init(void)
{
	major_num = register_chrdev(0, "MyCharDriver", &fops);
	printk(KERN_INFO "Char driver loaded successfully with major number:%d\n", major_num);
	return 0;
}

static void hello_exit(void)
{
	unregister_chrdev(major_num, "MyCharDriver");
}

module_init(hello_init);
module_exit(hello_exit);
