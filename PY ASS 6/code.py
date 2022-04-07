#python coding
def covert_binary():
	global num1
	global num2

	print(f'Num1: {num1}\tNum2: {num2}!')
	print('BINARY CONVERSION!')
	print('Num1: ',bin(num1), ' Num2: ',bin(num2),'\n')


def biwtise_logical_and():
	global num1
	global num2
	global num3

	num3 = num1 & num2

	print('LOGICAL AND OPERATION\t')
	print('Num1: ',bin(num1), ' Num2: ',bin(num2))
	print('Num1 AND Num2: ',bin(num3),'\n')


def bitwise_logical_or():
	global num1
	global num2
	global num3

	num3 = num1 | num2
	
	print('LOGICAL OR OPERATION\t')
	print('Num1: ',bin(num1), ' Num2: ',bin(num2))
	print('Num1 OR Num2: ',bin(num3),'\n')

def bitwise_logical_xor():
	global num1
	global num2
	global num3

	num3 = num1 ^ num2 

	print('LOGICAL XOR OPERATION\t')
	print('Num1: ',bin(num1), ' Num2: ',bin(num2))
	print('Num1 XOR Num2: ',bin(num3),'\n')


def bitwise_logical_not():
	global num1
	global num2
	global num3

	num1_not =  ~num1
	num2_not = ~ num2  

	print('LOGICAL NOT OPERATION\t')
	print('Num1: ',bin(num1), ' Num2: ',bin(num2))
	print(f'Num1 NOT: {num1_not}, Binary: ',bin(num1_not))
	print(f'Num2 NOT: {num2_not}, Binary: ',bin(num2_not),'\n')


def left_shift():
	print('BITWISE LEFT SHIFT\t')
	num=int(input('Enter Number: '))
	lshif = num << 2
	
	print('Number: ',bin(num))
	print(f'Left Shift of {num}: ',bin(lshif),'\n')


def right_shift():
	print('BITWISE RIGHT SHIFT\t')
	num=int(input('Enter Number: '))
	rshif = num >> 2

	print('Number: ',bin(num))
	print(f'Right Shift of {num}: ',bin(rshif),'\n')


if __name__ == '__main__':
	num1=int(input('Enter Value of Number 1: '))
	num2=int(input('Enter Value of Number 2: '))
	num3=0

	if type(num1) == int and type(num2) == int:
		print(f'{num1} and {num2} are Integers!\n')
	else:
		print(f'{num1} and {num2} are not Integers!\n')
		exit()

	covert_binary()

	menu="""
		1. Perform Logical AND Operation!
		2. Perfrom Logical OR Operation!
		3. Perfrom Lofical XOR Operation!
		4. Perform Logical NOT Operation!
		5. Perform Right Bit Shift!
		6. Perfrom Left Bit Shift!
		0. Quit
	"""
	print(menu)
	
	choic=' '
	while choic!='0':
		choic=input('Enter Option: ')
		if choic=='1':
			biwtise_logical_and()
		elif choic=='2':
			bitwise_logical_or()
		elif choic=='3':
			bitwise_logical_xor()	
		elif choic=='4':
			bitwise_logical_not()
		elif choic=='5':
			right_shift()
		elif choic=='6':
			left_shift()
		elif choic=='0':
			exit()
		else:
			print('Invalid Option Choosen!')
