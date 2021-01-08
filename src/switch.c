#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/errno.h> /* error codes */
#include <linux/fcntl.h> /* O_ACCMODE */
#include <linux/fs.h>    /* everything... */
#include <linux/proc_fs.h>
#include <linux/slab.h>    /* kmalloc() */
#include <linux/types.h>   /* size_t */
#include <linux/uaccess.h> /* copy_from/to_user */

#define GPIO_LED 2

MODULE_LICENSE("Dual BSD/GPL");

ssize_t sw_read(struct file *filp, char *buf, size_t count,
                    loff_t *f_pos);
ssize_t sw_write(struct file *filp, const char *buf, size_t count,
                     loff_t *f_pos);
                     
struct file_operations sw_fops = {
	.read = sw_read,
	.write = sw_write
};

char* sw_buf;

static int switch_init(void) {
	// register device
	register_chrdev(60, "sw", &sw_fops);
	sw_buf = kmalloc(1, GFP_KERNEL);
	memset(sw_buf, 0, 1);
	
	// set up gpio
	gpio_direction_output(GPIO_LED, 0);
	
	// blink 3 times;
	uint8_t i = 0;
	for (; i < 5; i++) {
		mdelay(100);
		gpio_set_value(GPIO_LED, 1);
		mdelay(200);
		gpio_set_value(GPIO_LED, 0);
	}

	gpio_set_value(GPIO_LED, 1);
	printk("<1> switch activated\n");
	return 0;
}

static void switch_exit(void) {
	gpio_set_value(GPIO_LED, 0);
	printk("<1> switch deactivated\n");
}

module_init(switch_init);
module_exit(switch_exit);


ssize_t sw_read(struct file *filp, char *buf, size_t count, loff_t *f_pos) {
	if (copy_to_user(buf, sw_buf, 1)) {
		return 0;
	}
	
	printk("READ: %c\n", sw_buf[0]);
    
    return 1;
}
						
ssize_t sw_write(struct file *filp, const char *buf, size_t count, loff_t *f_pos) {
	if (count < 1) return 0;
	if (copy_from_user(sw_buf, buf, 1)) {
		return 0;
	}
	
    printk("WRITE: %c\n", sw_buf[0]);
    
    gpio_set_value(GPIO_LED, sw_buf[0] == 'H' ? 1 : 0);
    
    return count;
}
						 
