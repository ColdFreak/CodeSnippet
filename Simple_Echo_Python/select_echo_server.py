#!/usr/bin/env python

"""
An echo server that uses select to handle multiple clients at a time. 
Entering any line of input at the terminal will exit the server. 
"""

import select
import socket
import sys

host = ''
port = 50000
backlog = 5
size = 1024

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host,port))
server.listen(backlog)
input = [server, sys.stdin]	# whatever from socket or from keyboard is input
running = 1

while running:
	inputready, outputready, exceptready = select.select(input,[],[])
	
	for s in inputready:
		# new client try to contact the server
		if s == server:
			# handle the server socket
			client, address = server.accept()
			input.append(client) # put new user to input
		elif s == sys.stdin:
			#handle standard input
			junk = sys.stdin.readline()
			running = 0
		else:
			# handle all other sockets
			# probably from new client
			data = s.recv(size)
			if data:
				s.send(data)
			else:
				s.close()
				input.remove(s) # remove client from input
server.close()