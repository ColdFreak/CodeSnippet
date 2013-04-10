#!/usr/bin/env python

"""
A simple echo server
"""
import socket
import sys   # 24th line
host = ''
port = 50000
backlog = 5
size = 1024
s = None
try:
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.bind((host, port))
	s.listen(backlog)

except socket.error, (value, message): #The return value of the socket is a tuple 
									   #consisting of an error code and message.
	if s:
		s.close()
	print "Could not open socket: " + message # if server is executed second time
											  # address already in use error will be displayed
	sys.exit(1)
	
while 1:
	client, address = s.accept()
	data = client.recv(size)
	if data:
		client.send(data)
	client.close()