#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define BUFFER_MAX_SIZE	1024

MODULE_AUTHOR("Bhaskar");
MODULE_LICENSE("GPL/BSD");
MODULE_VERSION("1.0");
MODULE_SUPPORTED_DEVICE("Dummy driver");

int major_num;
char driver_buf[BUFFER_MAX_SIZE];

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

ssize_t myread(struct file *filep, char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Read function called.\n");
	raw_copy_to_user(ubuf, driver_buf + filep->f_pos, nbytes);
	filep->f_pos += nbytes;
	printk(KERN_INFO "File position from read entry point:%lld\n", filep->f_pos);
	return 0;
}

ssize_t mywrite(struct file *filep, const char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Write function called.\n");
	raw_copy_from_user(driver_buf + filep->f_pos, ubuf, nbytes);
	filep->f_pos += nbytes;
	printk(KERN_INFO "File position from write entry point:%lld\n", filep->f_pos);
	return 0;
}

loff_t mylseek(struct file *filep, loff_t offset, int whence)
{
	int newpos;
	printk(KERN_INFO "llseek function called.\n");
	switch(whence)
	{
		case SEEK_SET:
			printk(KERN_INFO "llseek called with SEEK_SET.\n");
			newpos = offset;
			break;
		case SEEK_END:
			printk(KERN_INFO "llseek called with SEEK_END.\n");
			newpos = BUFFER_MAX_SIZE + offset;
			break;
		case SEEK_CUR:
			printk(KERN_INFO "llseek called with SEEK_CUR.\n");
			newpos = filep->f_pos + offset;
			break;
	}
	filep->f_pos = newpos;
	printk(KERN_INFO "New file position is:%d\n", newpos);
	return newpos;
}

struct file_operations fops = {
	.open = myopen,
	.read = myread,
	.write = mywrite,
	.llseek = mylseek,
	.release = myclose
};

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
