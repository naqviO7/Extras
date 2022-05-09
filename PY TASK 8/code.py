import os
import math
import random
from tkinter import *
from tkinter import filedialog

class Cube:
	def __str__(self):
		side = 3.0

		Area = 6 * (side * side)

		return f'Area of Cube: {Area}\nClass:{type(self).__name__}\n'

	def findArea(self):
		side = 3.0

		Area = 6 * (side * side)
		print(f"Area of Cube: {Area}")

	def display(self):
		print(f'Class: {type(self).__name__}') 


class Circle:
	def __str__(self):
		radius = 4.3

		Area = math.pi * radius * radius

		return f'Area of Circle: {Area}\nClass:{type(self).__name__}\n'

	def findArea(self):
		radius = 4.3

		Area = math.pi * radius * radius
		print(f"Area of Circle: {Area}")

	def display(self):
		print(f'Class: {type(self).__name__}')


class Square:
	def __str__(self):
		side=4.0

		Area = side * side

		return f'Area of Square: {Area}\nClass:{type(self).__name__}\n'

	def findArea(self):
		side=4.0

		Area = side * side
		print(f"Area of Square: {Area}")

	def display(self):
		print(f'Class: {type(self).__name__}')


def program_menu():
	print(' ________________________________________')
	print('| 1 -- Save results in a file            |')
	print('| 2 -- Print results on screen           |')
	print('| 3 -- Print results inside GUI Windows  |')
	print('| 4 -- Exit                              |')
	print('|________________________________________|')


if __name__=='__main__':
	objarr=[]
	num=random.randint(0,2)
	
	if num==0:
		for obj in range(10):
			cir=Circle()
			print(f'Object Number:{obj}\n{cir.__str__()}')
			objarr.append(cir)
	
	elif num==1:
		for obj in range(10):
			sq=Square()
			print(f'Object Number:{obj}\n{sq.__str__()}')
			objarr.append(sq)
	
	elif num==2:
		for obj in range(10):
			c=Cube()
			print(f'Object Number:{obj}\n{c.__str__()}')
			objarr.append(c)
	
	else:
		print(f'{num} is Out of Index.')
	
	os.system('cls')

	while True:
		program_menu()
		opt=int(input('Enter Option: '))
		
		if opt == 1:
			filname=input('Enter name of file: ')
			with open(filname,'w') as f:
				for i in range(10):
					f.write(objarr[i].__str__())
				print(f'Arrays are stored in {filname}')

		elif opt == 2:
		 	filname=input('Enter name of file: ')
		 	with open(filname,'rb') as f:
		 		print(f'Reading data from {filname}')
		 		print(f.read())

		elif opt == 3:
			def openFile():
				filepath = filedialog.askopenfilename(initialdir="C:\\Users\\naqviO7\\Desktop",
					title="Open File",
					filetypes= (("text files","*.txt"),
						("all files","*.*")))
				file = open(filepath,'r')
				print(file.read())
				file.close()
			window = Tk()
			window.geometry('30x40')
			button = Button(text="Open",command=openFile)
			button.pack()
			window.mainloop()

		elif opt == 4:
			print('Thanks message before Exiting.')
			exit()

		else:
			print(f'{opt} is Invalid Option')
#ENDOFCODE
