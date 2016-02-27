INSTALLDIR = $(shell pwd)/modules
ifneq ($(KERNELRELEASE),)
	obj-m := init_sc.o 
	init_sc-objs := init_function.o exit_function.o
else
KERNDIR ?= /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
		$(MAKE) -C $(KERNDIR) M=$(PWD) modules
			@rm -rf $(INSTALLDIR)
		@mkdir $(INSTALLDIR)
		@mv *.ko *.mod.c *.o .*.cmd $(INSTALLDIR)

clean:
		rm -rf $(INSTALLDIR)
		rm -rf Module.symvers
		rm -rf modules.order 

endif

