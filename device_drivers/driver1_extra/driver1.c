#include<linux/kernel.h>
#include<linux/module.h>

int hello_init(void)
{
	printk(KERN_ALERT "Bhaskar: Moduel loaded successfully\n");
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Bhaskar: Module unloaded successfully\n");
}

module_init(hello_init);
module_exit(hello_exit);
