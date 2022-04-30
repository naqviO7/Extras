description="""
	First I have crated function called question. 
	It takes character list as arguement.
	It checks for the string that contains question mark.
	It displayes that string.
	Second i have created another function called occurance.
	It will check for the commmon character appears in all items.
	It displays result to user.
"""

from collections import Counter

charslist=["barrack","obar?ma","?america","war","russia?","mak?er"]
ques="^\\?+$"

def question(charslist):
	print('Question marks check.')

	for char in charslist:
		if ques in char:
			print(f'{char} contains question mark')


def occurance(charslist):
	print('Common character check.')

	print('Character a appears in all items.')
	for common in charslist:
		con=Counter(common)	
		print(f"{common} contains {con['a'] } a")
	
	print('Character r appears in all items.')
	for common in charslist:
		print(f"{common} contains {con['r']} r")

if __name__=='__main__':
	question(charslist)
	occurance(charslist)
