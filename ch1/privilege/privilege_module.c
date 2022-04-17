#include <linux/module.h>     /* Needed by all modules */
#include <linux/kernel.h>     /* Needed for KERN_INFO */
#include <linux/init.h>       /* Needed for the macros */

///< The license type -- this affects runtime behavior
MODULE_LICENSE("GPL");

///< The author -- visible when you use modinfo
MODULE_AUTHOR("Balakumaran K");

///< The description -- see modinfo
MODULE_DESCRIPTION("A program to display privilege levels!");

///< The version of the module
MODULE_VERSION("0.1");

static u64 get_cr0(void)
{
   u64 x11 = 0;
    __asm__ __volatile__("movq %%cr0, %0;"
          :"=r"(x11)
          :);
    return x11;
}


static int __init hello_start(void)
{
    printk(KERN_INFO "Loading privilege module...\n");
    printk(KERN_INFO "CR0: %lld\n", get_cr0());
    return 0;
}

static void __exit hello_end(void)
{
    printk(KERN_INFO "Goodbye\n");
}

module_init(hello_start);
module_exit(hello_end);
