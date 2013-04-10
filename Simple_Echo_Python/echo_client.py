#!/usr/bin/env python

"""
A simple echo client
Run this without the server running
the error will be caught
"""

import socket
import sys

host = '192.168.1.100'
port = 50000
size = 1024
s = None
try:
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((host, port))
except socket.error, (value, message):
	if s:
		s.close()
	print "Could not open socket: " + message
	sys.exit(1)

sys.stdout.write('%')

while 1:
	# read from keyboard
	line = sys.stdin.readline()
	if line == ' ':   # what does this mean 
		break
	s.send(line)
	data = s.recv(size)
	sys.stdout.write(data)
	sys.stdout.write('%')
s.close()