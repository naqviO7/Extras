import sys
import socket
import argparse
import re

parser = argparse.ArgumentParser(description ='Send HTTP methods to a URL')
parser.add_argument('host')
parser.add_argument('method')
parser.add_argument('URI', nargs='?', default='/')
parser.add_argument('port', type=int, nargs='?', default=80)
args = parser.parse_args()

messages={'get': "GET ", 'options': "OPTIONS ", 'head': "HEAD ", 'trace': "TRACE ", 'put': "PUT ", 'connect': "CONNECT "}

try:
	args.method in messages
except:
	print ('Invalid method. Methods are: get, options, head, trace, put, connect')
	sys.exit()
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    ip = socket.gethostbyname(args.host)
except socket.error:
	print ("Socket creation failed")
	sys.exit()
except socket.gaierror:
	print ("Hostname could not be resolved. Exiting")
	sys.exit()
finally:
    s.connect((ip, args.port))

#endmsg = args.URI+" HTTP/1.1\r\nHOST: "+args.host+ "\r\n\r\n"
message = args.method+" HTTP/1.1\r\nHOST: "+args.host+ "\r\n\r\n"


try:
    s.sendall(message.encode('utf-8'))
    reply = s.recvfrom(1024)
except socket.error:
    print("socket error", socket.errno)

finally:
    #print("closing connection:\n")
    s.close()

#decodes the string using the codec registered for encoding (urf-8)
str_data = reply[0].decode("utf-8")
print(str_data)


#returns a list with all the lines in string array
headers = str_data.splitlines()

#regex to search matches string 'Server'
for s in  headers:
    if re.search('Server:', s):
        s = s.replace('Server', "")
        print("Web Server => %s" %(s))
