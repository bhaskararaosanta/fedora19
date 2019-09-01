#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

int major_num;

int myopen(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Bhaskar: open function called.\n");
	return 0;
}

int myclose(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Bhaskar: close function called.\n");
	return 0;
}

ssize_t myread(struct file *filep, char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Bhaskar: read function called.\n");
	return 0;
}

ssize_t mywrite(struct file *filep, const char *ubuf, size_t nbytes, loff_t *offet)
{
	printk(KERN_INFO "Bhaskar: write function called.\n");
	return 0;
}

struct file_operations fops = {
	.open = myopen,
	.release = myclose,
	.read = myread,
	.write = mywrite
};

static int hello_init(void)
{
	printk(KERN_INFO "Bhaskar:  module loaded successfully.\n");

	major_num = register_chrdev(0, "MyCharDriver", &fops);
	printk(KERN_INFO "Driver registered with major number:%d\n", major_num);

	return 0;
}

static void hello_exit(void)
{
	unregister_chrdev(major_num, "MyCharDriver");
	printk(KERN_INFO "Bhaskar: module unloaded successfully.\n");
}

module_init(hello_init);
module_exit(hello_exit);

