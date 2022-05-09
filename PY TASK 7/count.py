from collections import Counter

def my_counter(any_integer):
	my_number=2222
	any_integer=any_integer*7777
	any_integer=my_number*any_integer
	any_integer=any_integer**4 
	print(f'Generated Integers: {any_integer}')
	
	numbers= [int(x) for x in str(any_integer)]
	occurence_count = Counter(numbers)

	return occurence_count.most_common(1)[0][0]

if __name__ == '__main__':
	integer=int(input('Enter 4 digit number: '))
	print(f'The most common digit is {my_counter(integer)}')
