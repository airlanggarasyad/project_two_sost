#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */


#define DRIVER_AUTHOR "Airlangga Rasyad F <fairlanggarasyad@mail.ugm.ac.id>"
#define DRIVER_DESC   "Project 2 Sistem Operasi pada Sistem Tertanam"

MODULE_LICENSE("GPL");

static int __init hello_kernel_init(void) {
    printk(KERN_INFO "Nama : Airlangga Rasyad Fidiyanto");
    printk(KERN_INFO "NIM  : 19/443562/TK/48758");

    return 0;
}

static void __exit hello_kernel_exit(void) {
    printk(KERN_INFO "Exiting kernel module...");
}

module_init(hello_kernel_init);
module_exit(hello_kernel_exit);
