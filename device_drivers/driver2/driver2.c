#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/slab.h>

void *ptr1, *ptr2;
int *iptr;
char *cptr;

int hello_init(void)
{
	printk(KERN_ALERT "Bhaskar: Module loaded successfully\n");
	ptr1 = kmalloc(100, GFP_KERNEL);
	ptr2 = kmalloc(200, GFP_KERNEL);

	if(ptr1 != NULL)
	{
		iptr = (int *)ptr1;
		*iptr = 12345;
		printk(KERN_ALERT "Memory allocated for first kmalloc call:%p\n", ptr1);
		printk(KERN_ALERT "Value stored at memory pointed by ptr1:%d\n", *iptr);
	}
	
	if(ptr2 != NULL)
	{
		cptr = (char *)ptr2;
		*cptr = 'A';
		printk(KERN_ALERT "Memory allocated for second kmalloc call:%p\n", ptr2);
		printk(KERN_ALERT "Value stored at memory pointed by ptr1:%c\n", *cptr);
	}
	
	return 0;
}

void hello_exit(void)
{
	printk(KERN_ALERT "Bhaskar: Module unloaded successfully\n");
	kfree(ptr1);
	kfree(ptr2);
}

module_init(hello_init);
module_exit(hello_exit);
