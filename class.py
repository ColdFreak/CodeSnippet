#!/usr/bin/python -tt
# create a simple class

class testClass(object):
	print "Creating New Class\n======"
	num = 5
	def __init__(self, st):
		self.stri = st
	def printClass(self):
		print "Number = %d" % self.num
		print "String = %s" % self.stri

tc= testClass("Five")
tc.printClass()
tc.num = 10
tc.stri = "Ten"
tc.printClass()
"""object-->st-->stri"""
