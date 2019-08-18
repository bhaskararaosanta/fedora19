#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/ioport.h>

static int hello_init(void)
{
	printk(KERN_INFO "Bhaskar: IO memory request module loaded successfully.\n");
	printk(KERN_INFO "check region between 0x3E8 - 0x3EF=%d\n", check_region(0x3E8, 8));
	if(check_region(0x3E8, 8) == 0)
	{
		request_region(0x3E8, 8, "BhaskarRegion");
	}
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_INFO "Bhaskar: IO memeory request module unloaded successfully.\n");
	release_region(0x3E8, 8);
}

module_init(hello_init);
module_exit(hello_exit);
