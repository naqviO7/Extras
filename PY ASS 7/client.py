import os
import socket
import hashlib

IP='127.0.0.1'
PORT = 9000	
ADDR = (IP, PORT)
SIZE = 1024
FORMAT = "utf-8"

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)

file_n=input('Enter File Name: ')
file = open(file_n, "r")
#data = file.read()

with open(file_n,'rb') as f:
	bytes = f.read()
	haash = hashlib.md5(bytes).hexdigest()
	length=len(file_n)

	print(f'SEND: {file_n}\nMD5 HexDigest: {haash}\n Length: {length}')

client.send(file_n.encode(FORMAT))
msg = client.recv(SIZE).decode(FORMAT)
print(f"[SERVER]: {msg}")

client.send(file_n.encode(FORMAT))
msg = client.recv(SIZE).decode(FORMAT)
print(f"[SERVER]: {msg}")

file.close()

client.close()
