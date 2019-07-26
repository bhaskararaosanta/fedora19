#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
//#include<asm/uaccess.h>
#include<linux/uaccess.h>

#define	BUFFER_MAX_SIZE	1024

int major_num;
char driver_buf[BUFFER_MAX_SIZE];

int myopen(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Bhaskar: Open function called\n");
	//MOD_INC_USE_COUNT;
	return 0;
}

int myclose(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "Bhaskar: Close function called\n");
	//MOD_DEC_USE_COUNT;
	return 0;
}

ssize_t myread(struct file *filep, char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Bhaskar: Read function called\n");
	copy_to_user(ubuf, driver_buf + filep->f_pos, nbytes);
	filep->f_pos += nbytes;
	printk("Read:%d\n", filep->f_pos);
	return 0;
}

ssize_t mywrite(struct file *filep, const char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Bhaskar: Write function called\n");
	printk("Write:%d\n", filep->f_pos);
	copy_from_user(driver_buf+filep->f_pos, ubuf, nbytes);
	filep->f_pos += nbytes;
	return 0;
}

loff_t mylseek(struct file *filep, loff_t offset, int whence)
{
	int newpos;
	printk(KERN_INFO "Bhaskar: Lseek function called\n");
	switch(whence)
	{
		case SEEK_SET:
			printk("***lseek called with SEEK_SET***\n");
			newpos = offset;
			break;
		case SEEK_END:
			printk("***lseek called with SEEK_END***\n");
			newpos = BUFFER_MAX_SIZE + offset;
			break;
		case SEEK_CUR:
			printk("***lseek called with SEEK_CUR***\n");
			newpos = filep->f_pos + offset;
			break;
	}
	filep->f_pos = newpos;
	printk("New position is:%d\n", newpos);
	return 0;
}

struct file_operations fops = {
	.open = myopen,
	.read = myread,
	.write = mywrite,
	.llseek = mylseek,
	.release = myclose
};

int hello_init(void)
{
	int ret;
	printk(KERN_INFO "Bhaskar: Module loaded successfully\n");
	major_num = register_chrdev(0, "My_Driver", &fops);
	printk("Bhaskar: Driver register with Major Number:%d\n", major_num);
	return 0;
}

void hello_exit(void)
{
	printk(KERN_INFO "Bhaskar: Module unloaded successfully\n");
	unregister_chrdev(major_num, "My_Driver");
}

module_init(hello_init);
module_exit(hello_exit);
