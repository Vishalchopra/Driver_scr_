#!/bin/bash

remove_file()
{

	rm -rf modules
	rm -rf Module.symvers
	rm -rf modules.order
	if [ $1 == 1 ]
	then 
		exit 0
	else
		echo "End of the script"
	fi
}

if ( make )
then
	read
else
	echo "Make Fail"
	exit 0
fi

echo "Do you want to insert driver to kernel"
echo "y/n"
read choice

if [ $choice == "yes" ]
then
	insmod ./modules/init_sc.ko nod=5
else
	echo "Not interested in inserting driver"
	remove_file 1
fi

cat /proc/devices
read


dmesg 
read

echo "Do you want to remove driver y/n"
read choice

if [ $choice == "yes" ]
then
	rmmod init_sc.ko
else
	echo "You need to remove the driver"
fi

cat /proc/devices
read

remove_file 0
