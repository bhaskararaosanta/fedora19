#include <linux/module.h>
#include <linux/kernel.h>

static unsigned int ivar = 20;
static unsigned long lvar = 1000;

module_param(ivar, int, 0);
module_param(lvar, long, 0);
MODULE_PARM_DESC(ivar, "ivar is an integer");
MODULE_PARM_DESC(lvar, "lvar is a long");

MODULE_AUTHOR("Bhaskar");
MODULE_DESCRIPTION("This is dummy driver");
MODULE_SUPPORTED_DEVICE("Dummy");
MODULE_LICENSE("BSD/GPL");

static int hello_init(void)
{
	printk(KERN_INFO "Bhaskar: dummy driver2 loaded successfully.\n");
	printk(KERN_INFO "Module parameters are:\n");
	printk(KERN_INFO "ivar = %d\n", ivar);
	printk(KERN_INFO "lvar = %ld\n", lvar);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "Bhaskar: dummy driver2 unloaded successfully.\n");
}

module_init(hello_init);
module_exit(hello_exit);

