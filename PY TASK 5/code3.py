description="""
	First I have crated Recurrsion function called coverage. 
	It takes a number as arguement.
	It perfroms recursion algorith to do some stuff and displays the result till the end.
	This algortihm stops when num==1.
"""

def coverage(num):
	if num % 2 == 0:
		val=num/2
		print(val)
		return val

	else:
		val=num
		while val != 1:
			val=num*3
			val=val+1
			print(val)
			val=val/2
			print(val)
			return coverage(val)


if __name__ == '__main__':
	try:
		num=int(input('Enter Number: '))
		coverage(num)
	except ValueError:
		print('Enter Number to Perfrom Recurrsion.')
