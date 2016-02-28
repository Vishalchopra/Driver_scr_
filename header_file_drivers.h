#include<linux/init.h>
#include<linux/module.h>
#include<linux/sched.h>
#include<linux/fs.h>
#include<linux/moduleparam.h>
#include<linux/slab.h>
#include<linux/cdev.h>

#ifndef MACROS
#define MACROS

	#ifndef DEVNAME
	#define DEVNAME "chardev"
	#endif

	#ifndef DEBUG
	#define DEBUG
	#endif

	#ifndef MAJORNO
	#define MAJORNO 0
	#endif

	#ifndef MINORNO
	#define MINORNO 0
	#endif

	#ifndef NOD
	#define NOD 5
	#endif

#endif

MODULE_LICENSE("Dual BSD/GPL");
