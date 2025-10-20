#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("James");
MODULE_DESCRIPTION("First loadable kernel");

static struct proc_dir_entry *custom_proc_node;
struct proc_ops driver_proc_ops = {};

static int my_module_init(void) {
	printk("my_module_init: entry\n");
	custom_proc_node = proc_create("my_driver",0,NULL,&driver_proc_ops);
	if(custom_proc_node == NULL){
		printk("my_module_init: error\n");
		return -1;
	}
	printk("my_module_init: exit\n");
	return 0;
}

static void my_module_exit(void) {
	printk("my_module_exit: entry\n");
	proc_remove(custom_proc_node);
	printk("my_module_exit: exit\n");
}

module_init(my_module_init);
module_exit(my_module_exit);
