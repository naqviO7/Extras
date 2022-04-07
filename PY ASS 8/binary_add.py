# function which will convert 
	#decimal numbers to binary number
def conv_bin():
	global num1
	global num2

	print(f'\nNumbers in Decimal Form!\nNum1: {num1}\tNum2: {num2}!')
	print(f'\nNumbers in Binary Form!\nNum1: {bin(num1)}\tNum2: {bin(num2)}\n')


#function which will add both numbers
def add_nums():
	global num1
	global num2
	global summ

	#adding both numbers
	summ = num1 + num2
	#converting their sum into binary from
	print(f'Binary Sum of {bin(num1)} and {bin(num2)} is {bin(summ)}')

if __name__=='__main__':	
	#taking input from user
	num1=int(input('Enter Number: '))
	num2=int(input('Enter Numbber: '))
	summ=0

	#calling bth functions
	conv_bin()
	add_nums()
