#!/usr/bin/env python

"""
A simple echo client
"""

import socket

host = '192.168.1.100'
port = 50000
size = 1024
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))
s.send('Hello, world')
data = s.recv(size) # 一次性最大处理size个字节的数据
s.close()
print 'Received', data