#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<asm/uaccess.h>

volatile static int is_open = 0;
static char message[1024];
int num_bytes = 0;
int major_num;

ssize_t hello_read(struct file *filep, char __user *outb, size_t nbytes, loff_t *offset)
{
	int bytes_read = 0;
	if(*offset == NULL) return -EINVAL;
	if(*offset >= num_bytes) return 0;
	while((bytes_read < nbytes) && (*offset < num_bytes))
	{
	//	put_user(message[(*offset)], outb[bytes_read]);
		*offset++;
		bytes_read;
	}
	return bytes_read;

}

ssize_t hello_write(struct file *filep, const char __user *inpb, size_t nbytes, loff_t *offset)
{
	printk(KERN_INFO "Error = cannot handle write\n");
	return -EINVAL;


}

int hello_open(struct inode *inodep, struct file *filep)
{
	if(is_open == 1)
	{
		printk(KERN_INFO "Error - hello device already opened\n");
		return -EBUSY;
	}
	is_open = 1;
	try_module_get(THIS_MODULE);

}

int hello_close(struct inode *inodep, struct file *filep)
{
	if(is_open == 0)
	{
		printk(KERN_INFO "Error - device wasn't opened\n");
		return -EBUSY;
	}
	is_open = 0;
	module_put(THIS_MODULE);

}






struct file_operations fops = {
	.open = hello_open,
	.owner = THIS_MODULE,
	.read = hello_read,
	.write = hello_write,
	.release = hello_close
};

/* struct file_operations fops = {
	open : hello_open,
 	owner : THIS_MODULE,
	read : hello_read,
	write : hello_write,
	release : hello_close
}; */

static int __init hello_start(void)
{
	printk(KERN_INFO "Hello, I am here to help\n");
	major_num = register_chrdev(0, "hellodriver", &fops);
	printk(KERN_INFO "Major number is:%d\n", major_num);
	strncpy(message, "Hello world.", 1023);
	num_bytes = strlen(message);
	
	return 0;
}

static void __exit hello_end(void)
{
	printk(KERN_INFO "Goodbye, I hope I was helpful\n");
	unregister_chrdev(major_num, "hellodriver");
}

module_init(hello_start);
module_exit(hello_end);
