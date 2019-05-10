// make -C /usr/src/linux-headers-4.18.0-10-generic M=`pwd` modules
// dmesg -w
// sudo insmod param.ko whom="hoge" howmany=5
// sudo rmmod param

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "world";
static int howmany = 1;
module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);

static int param_init(void) {
  printk(KERN_ALERT "Hello, %s, %d\n", whom, howmany);
  return 0;
}

static void param_exit(void) {
  printk(KERN_ALERT "Goodbye, cruel world\n");
  return;
}

module_init(param_init);
module_exit(param_exit);
