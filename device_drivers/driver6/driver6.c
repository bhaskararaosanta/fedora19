#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include <linux/fs.h>

static int myopen(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Bhaskar: open function called.\n");
	return 0;
}

static int myclose(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Bhaskar: close or release function called.\n");
	return 0;
}

static ssize_t myread(struct file *filep, char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Bhaskar: Read function called.\n");
	return 0;
}

static ssize_t mywrite(struct file *filep, const char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Bhaskar: Write function called.\n");
	return 0;
}

struct file_operations fops = {
open: myopen,
read: myread,
write: mywrite,
release: myclose,
};
	
int major_num;

static int hello_init(void)
{
	printk(KERN_INFO "Bhaskar: char driver loaded successfully.\n");
	major_num = register_chrdev(0, "MyDriver", &fops);
	printk(KERN_INFO "Bhaskar:Driver register with major number = %d.\n", major_num);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "Bhaskar: char driver unloaded successfully.\n");
	unregister_chrdev(major_num, "MyDriver");
}

module_init(hello_init);
module_exit(hello_exit);

