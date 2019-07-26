#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<asm/uaccess.h>
//#include<linux/uaccess.h>

#define	BUFFER_MAX_SIZE	1024

int major_num;
char driver_buf[BUFFER_MAX_SIZE];

int myopen(struct inode *inodep, struct file *filep)
{
	printk(KERN_ALERT "Bhaskar: Open function called from application prog\n");
	return 0;
}

int myclose(struct inode *inodep, struct file *filep)
{
	printk(KERN_ALERT "Bhaskar: Release function called from application prog\n");
	return 0;
}

ssize_t myread(struct file *filep, char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_ALERT "Bhaskar: Read function called from application prog\n");
	raw_copy_to_user(ubuf, driver_buf + filep->f_pos, nbytes);  //if we want to use asm/uaccess.h
	//copy_to_user(ubuf, driver_buf + filep->f_pos, nbytes); //if we want to use linux/uaccess.h
	filep->f_pos += nbytes;
	printk("Read: %lld\n", filep->f_pos);
	return 0;
}

ssize_t mywrite(struct file *filep, const char *ubuf, size_t nbytes, loff_t *offset)
{
	printk(KERN_ALERT "Bhaskar: Write function called from application prog\n");
	printk("Write:%lld\n", filep->f_pos);
	raw_copy_from_user(driver_buf + filep->f_pos, ubuf, nbytes); //if we want to use asm/uaccess.h
	//copy_from_user(driver_buf + filep->f_pos, ubuf, nbytes); //if we want to use linux/uaccess.h
	filep->f_pos += nbytes;
	return 0;
}

loff_t mylseek(struct file *filep, loff_t offset, int whence)
{
	int newpos;
	printk(KERN_ALERT "Bhaskar: lseek function called from application prog\n");
	switch(whence)
	{
		case SEEK_SET:
			printk(KERN_ALERT "lseek called with SEEK_SET\n");
			newpos = offset;
			break;
			
		case SEEK_END:
			printk(KERN_ALERT "lseek called with SEEK_END\n");
			newpos = BUFFER_MAX_SIZE + offset;
			break;

		case SEEK_CUR:
			printk(KERN_ALERT "lseek called with SEEK_CUR\n");
			newpos = filep->f_pos + offset;
			break;
	}
	filep->f_pos = newpos;
	printk(KERN_ALERT "new position is :%d\n", newpos);
	return newpos;
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
	int ret, major_num;
	printk(KERN_ALERT "Bhaskar: Module loaded successfully\n");
	major_num = register_chrdev(0, "Mydriver", &fops);
	printk(KERN_ALERT "Bhaskar: Driver registered with major number:%d\n", major_num);
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Bhaslar: Module unloaded successfully\n");
	unregister_chrdev(major_num, "Mydriver");
}

module_init(hello_init);
module_exit(hello_exit);
