#include"header_file_drivers.h"
#include"declaration.h"
#include"fileoperation.h"

int majorno, minorno;
unsigned int nod;
dev_t dev, dev_temp;
struct DEV *sdev;
//struct file_operation fops;

module_param(nod, int, S_IRUGO);

void initialization(void)
{
	majorno = MAJORNO;
	minorno = MINORNO;
}

static int __init initialization_function(void)	/*__init means this function is used once only during initialization and bcs this function visible to 							this file only */
{
	int ret, dvar;
	dvar = ret = 0;

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
	sdev = (struct DEV *)kmalloc(sizeof(struct DEV) * nod, GFP_KERNEL);
	if(!sdev){
		#ifdef DEBUG
			printk(KERN_ERR "There is some problem in allocation\n");
		#endif
		goto OUT;
	}
	memset(sdev, '\0', sizeof(struct DEV) * nod);

	for(dvar = 0; dvar < nod; dvar++){
		cdev_init(&(sdev + dvar)->c_dev, &fops);
		(sdev + dvar)->c_dev.owner = THIS_MODULE;
		(sdev + dvar)->c_dev.ops = &fops;
		dev_temp = MKDEV(majorno, dvar);
		(sdev + dvar)->c_dev.dev = dev;
		if( !(cdev_add( &(sdev +dvar)->c_dev, dev_temp, nod)) ){
			#ifdef DEBUG
				printk(KERN_ERR "c_dev addition is sucessfull\n");
			#endif

		}else{
			#ifdef DEBUG
				printk(KERN_ERR "c_dev addition is not sucessfull\n");
			#endif
			goto OUT;
		}
	}
	return 0;
OUT:
	#ifdef DEBUG
		printk(KERN_INFO "There is some bug please fix it\n");
	#endif	
	return -1;
}

module_init(initialization_function);
