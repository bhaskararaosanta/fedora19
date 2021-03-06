#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/gpio.h>

#define	LED1	16

static struct timer_list blink_timer;

/* timer function called periodically */

static void blink_timer_func(unsigned long data)
{
	printk(KERN_INFO "%s\n", __func__);
	gpio_set_value(LED1, data);

	/* schedule next execution */
	blink_timer.data = !data; /* Makes LED to toggle */
	blink_timer.expires = jiffies + (1 * HZ); // 1 Sec
	add_timer(&blink_timer);
}

static int __init gpiomod_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
	// register, turn off
	ret = gpio_request_one(LED1, GPIOF_OUT_INIT_LOW, "led1");
	if(ret)
	{
		printk(KERN_ERR "Unable to request GPIOs:%d\n", ret);
		return ret;
	}
	// init timer, add timer function
	init_timer(&blink_timer);

	blink_timer.function = blink_timer_func;
	blink_timer.data = 1L; // initially turn on LED
	blink_timer.expires = jiffies + (1 * HZ); // 1 Sec
	add_timer(&blink_timer);

	return ret;
}

static void __exit gpiomod_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);

	// deactivate timer if running
	del_timer_sync(&blink_timer);

	// turn LED off
	gpio_set_value(LED1, 0);

	// unregister GPIO
	gpio_free(LED1);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bhaskar");
MODULE_DESCRIPTION("RPI Kernel module to blink on board LED.");

module_init(gpiomod_init);
module_exit(gpiomod_exit);
