#include"header_file_drivers.h"
#include"declaration.h"

int majorno, minorno;
unsigned int nod;
dev_t dev;

int initialization(void);
int initialization()
{
	majorno = MAJORNO;
	minorno = MINORNO;
	nod = NOD;
	return 0;
}

static int __init initialization_function(void)	/*__init means this function is used once only during initialization and bcs this function visible to 							this file only */
{
	int ret;
	ret = 0;

	#ifdef DEBUG
		printk(KERN_INFO "Hello World\n");
		printk(KERN_INFO "The Process is \" %s\" (pid %i)\n" , current->comm, current->pid);
	#endif

	initialization();

	if(majorno){
		dev = MKDEV(majorno, minorno);
		ret = register_chrdev_region(majorno, NOD, DEVNAME);
		if(ret < 0)
			goto OUT;
		else{
			#ifdef DEBUG
				printk(KERN_INFO "Char driver is register\n");
			#endif
		}			
	}else{
		ret = alloc_chrdev_region(&dev, minorno, nod, DEVNAME);
		if(ret < 0)
			goto OUT;
		else{
			#ifdef DEBUG
				printk(KERN_INFO "Char driver is register\n");
			#endif
		}			
		majorno = MAJOR(dev);
		#ifdef DEBUG
			printk(KERN_INFO "Char driver is register with major number %d\n", majorno);
		#endif
		
	}
	
	return 0;
OUT:
	#ifdef DEBUG
		printk(KERN_INFO "There is some bug please fix it\n");
	#endif	
	return -1;
}

module_init(initialization_function);
