#!/usr/bin/python

import os

print "Do you want to insert the driver"
print "yes/no"


if (os.system('make')):
	os.system('read')
else:
	print "Make Fail"
