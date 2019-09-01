#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define BUFFER_MAX_SIZE 1024
int major_num;
char driver_buf[BUFFER_MAX_SIZE];

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

loff_t mylseek(struct file *filep, loff_t offset, int whence)
{
	int newpos;
	printk(KERN_INFO "Bhaskar: lseek function called.\n");
	switch(whence)
	{
		case SEEK_SET:
			printk(KERN_INFO "lseek called with SEEK_SET\n");
			newpos = offset;
			break;

		case SEEK_END:
			printk(KERN_INFO "lseek called with SEEK_END\n");
			newpos = BUFFER_MAX_SIZE + offset;
			break;

		case SEEK_CUR:
			printk(KERN_INFO "lseek called with SEEK_CUR\n");
			newpos = filep->f_pos + offset;
			break;
	}
	filep->f_pos = newpos;
	printk(KERN_INFO "new position of file pointer is:%d\n", newpos);
	return newpos;
}

ssize_t myread(struct file *filep, char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Bhaskar: read function called.\n");
	copy_to_user(ubuf, driver_buf + filep->f_pos, nbytes);
	filep->f_pos += nbytes;
	printk(KERN_INFO "Read :%d\n", filep->f_pos);
	return 0;
}

ssize_t mywrite(struct file *filep, const char *ubuf, size_t nbytes, loff_t *offet)
{
	printk(KERN_INFO "Bhaskar: write function called.\n");
	printk(KERN_INFO "Write :%d\n", filep->f_pos);
	copy_from_user(driver_buf + filep->f_pos, ubuf, nbytes);
	filep->f_pos += nbytes;
	return 0;
}

struct file_operations fops = {
	.open = myopen,
	.release = myclose,
	.read = myread,
	.llseek = mylseek,
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

