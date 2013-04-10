#!/usr/bin/env python

"""Return a list of paths matching a pathname pattern
"""
import glob
list = glob.glob("/Users/wzj/C/*.c")
for file in list:
	print file


