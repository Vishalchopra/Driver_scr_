#include"header_file_drivers.h"
#include"declaration.h"

static void __exit exit_function(void)
{
	int ret;
	ret = 0;
	 unregister_chrdev_region(dev, nod);
	if(ret < 0)
		goto OUT;
	else{
		#ifdef DEBUG
			printk(KERN_INFO "unregister sucessfully\n");	
		#endif
	}	
	#ifdef DEBUG
		printk(KERN_INFO"Goodbye Cruel World\n");	
	#endif
OUT:
	#ifdef DEBUG
		printk(KERN_INFO "unregister  is not sucessful\n");	
	#endif
	
}

module_exit(exit_function);
