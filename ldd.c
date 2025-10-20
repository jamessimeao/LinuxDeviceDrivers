#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("James");
MODULE_DESCRIPTION("First loadable kernel");

static int my_module_init(void) {
	printk("Hello, world!\n");
	return 0;
}

static void my_module_exit(void) {
	printk("Good, Bye!\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
