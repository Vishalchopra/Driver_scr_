#include"header_file_drivers.h"
#include"declaration.h"

static void __exit exit_function(void)
{
	int ret, dvar;
	dvar = ret = 0;

	for(dvar = 0; dvar < nod; dvar++){
		cdev_del(&(sdev + dvar)->c_dev);
	}
	kfree(sdev);
	unregister_chrdev_region(dev, nod);
	#ifdef DEBUG
		printk(KERN_INFO"Goodbye Cruel World\n");	
	#endif
	
}

module_exit(exit_function);
