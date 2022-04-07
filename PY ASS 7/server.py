import os
import socket
import hashlib

IP='127.0.0.1'
PORT = 9000	
ADDR = (IP, PORT)
SIZE = 1024
FORMAT = "utf-8"

ERROR=0

print("[STARTING] Server is starting.")

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(ADDR)

print("[LISTENING] Server is listening.")
server.listen(5)

while True:
	conn, addr = server.accept()
	print(f"[NEW CONNECTION] {addr} connected.")

	try:
		filename = conn.recv(SIZE).decode(FORMAT)
		print(f"[RECV] Receiving the filename.")
		file = open(filename, "w")
		conn.send("Filename received.".encode(FORMAT))
		length=len(filename)

		print(f"[DISCONNECTED] {addr} disconnected.")
		os.system('exit')

		try:
			with open(filename,'rb') as f:
				bytes = f.read()
				haash = hashlib.md5(bytes).hexdigest()

				print(f'FOUND: {filename}\nMD5 HexDigest: {haash}\n Length: {length}')

				data = conn.recv(SIZE).decode(FORMAT)
				print(f"[RECV] Receiving the file data.")
				file.write(data)
				conn.send("File data received".encode(FORMAT))
			
			print(f"[DISCONNECTED] {addr} disconnected.")
			os.system('exit')
			
		except:
			print(f'NOTFOUND: {filename}\n')
			print(f"[DISCONNECTED] {addr} disconnected.")
			os.system('exit')

	except:
		filesize = os.stat(filename).st_size

		if filesize > SIZE:
			filename = conn.recv(SIZE).decode(FORMAT)
			print(f'TOO LARGE: {filename}\n Bad Request')
			print(f"[DISCONNECTED] {addr} disconnected.")
			os.system('exit')
		
		else:
			pass				
	file.close()

	conn.close()
		
print(f"[DISCONNECTED] {addr} disconnected.")
