#include <linux/module.h>
#include <linux/kernel.h>

static int hello_init(void)
{
	printk(KERN_INFO "Bhaskar: Module loaded successfully.\n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "Bhaskar: Module unloaded successfully.\n");
}

module_init(hello_init);
module_exit(hello_exit);
