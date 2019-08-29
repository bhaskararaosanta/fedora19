#include <linux/module.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/tty.h>	/* FOr fg_console, MAX_NR_CONSOLES */
#include <linux/kd.h>	/* For KDSETLED */
#include <linux/vt.h>
#include <linux/console_struct.h>

MODULE_DESCRIPTION("Example module illustrating the use of Keyboard KEDs.");
MODULE_AUTHOR("Bhaskar");
MODULE_LICENSE("GPL");

struct timer_list my_timer;
struct tty_driver *my_driver;
char kbledstatus = 0;

#define	BLINK_DELAY HZ/5
#define ALL_LEDS_ON 0x07
#define RESTORE_LEDS 0xFF

static void my_timer_func(unsigned long ptr)
{
	int *pstatus = (int *)ptr;
	if(*pstatus == ALL_LEDS_ON)
		*pstatus = RESTORE_LEDS;
	else
		*pstatus = ALL_LEDS_ON;
	
	(my_driver->ioctl)(vc_cons[fg_console].d->vc_tty, NULL, KDSETLED, *pstats);
	my_timer.expires = jiffies + BLINK_DELAY;
	add_timer(&my_timer);
}

static int __init kbleds_init(void)
{
	int i;
	printk(KERN_INFO "kbleds: loading\n");
	printk(KERN_INFO "kbleds: fgconsole is %x\n", fg_console);
	for(i = 0; i < MAX_NR_CONSOLES; i++)
	{
		if(!vc_cons[i].d)
			break;
		printk(KERN_INFO "poet_atkm: console[%i/%i] #%i, tty %lx\n", i, MAX_NR_CONSOLES, vc_cons[i].d->vc_num, (unsigned long)vc_cons[i].d->vc_tty);
	}
	printk(KERN_INFO "kbleds: finished scanning consoles\n");

	my_driver = vc_cons[fg_console].d->vc_tty->driver;
	printk(KERN_INFO "kbleds: tty driver magic %x\n", my_driver->magic);

	init_timer(&my_timer);
	my_timer.function = my_timer_func;
	my_timer.data = (unsigned long)&kbledstatus;
	my_timer.expires = jiffies + BLINK_DELAY;
	add_timer(&my_timer);

	return 0;
}

static void __exit kbleds_cleanup(void)
{
	printk(KERN_INFO "kbleds: unloading...\n");
	del_timer(&my_timer);
	(my_driver->ioctl)(vc_cons[fg_console].d->vc_tty, NULL, KDSETLED, RESTORE_LEDS);
}

module_init(kbleds_init);
module_exit(kbleds_cleanup);

