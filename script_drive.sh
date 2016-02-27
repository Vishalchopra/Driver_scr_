#!/bin/bash

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

echo "$choice" 
read

if [ $choice == "yes" ]
then
	insmod ./modules/init_sc.ko
else
	echo "Not interested in inserting driver"
	exit 0
fi

cat /proc/devices
read
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
cat /proc/devices
read



