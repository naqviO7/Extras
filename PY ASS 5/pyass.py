import os 

#variables defined 
total_safes=12
sec_code=';Cool123'
safes_used=4
availablesafe=[2,3,4,6,7,8,9,10] 
occupied_safes=[11,1,5,12]


#menu function for luggage system
def luggage_menu():
	print('-'*60)
	print('\tM\tE\tN\tU\t')
	print('-'*60)
	print('[+] 1 ==> Check how many safes are available?')
	print('[+] 2 ==> I want a new safe!')
	print('[+] 3 ==> I want to get Out something from my safe!')
	print('[+] 4 ==> I return my safe!')
	print('[!] 5 ==> Quit')
	print('-'*60,'\n')


#function to tell available vaults 
def number_vaults_free():
	global total_safes 
	global safes_used

	print('Vaults Available: ',total_safes-safes_used)
	return total_safes - safes_used


#function to create new vault
def new_vault():
	global total_safes
	global safes_used
	global occupied_safes
	global sec_code
	global availablesafe

	if safes_used < total_safes:
		print('Vaults are Available!')
		new_vault=int(input('Enter Safe Number: '))

		if new_vault not in occupied_safes:
			sec_cod=input('Enter Security Code: ')
			if sec_cod == sec_code:
				print(f'New Safe {new_vault} is Granted to You!')
				if sec_cod != sec_code:
					return -1
		else:
			print('Already Occupied Safe Selected')

	if availablesafe==occupied_safes:
		print('All Safes are Already Occupied!')
		return -2


#function to open vault
def open_vault():
	global sec_code
	global occupied_safes

	new_num=int(input('Enter Safe Number: '))
	seccode=input('Enter Security Code: ')
	
	if new_num not in occupied_safes:
		if seccode==sec_code:
			print(f'New Safe with {new_num} is Opened for You!')
			return True
	else:
		print('Security Code Error, Cannot Grant Access!')
		return False


#function to return vault
#optional functionality
def return_vault():
	global sec_code
	global occupied_safes
	
	new_num=int(input('Enter Safe Number: '))
	seccode=input('Enter Security Code: ')
	
	if new_num not in occupied_safes:
		if seccode == sec_code:
			print(f'New Safe with {new_num} is Returned to You!')
			return True
	else:
		print('Security Code Error, Cannot Grant Access!')
		return False


#main 
if __name__ == '__main__':
	os.system('cls')
	luggage_menu()

	opt=int(input('Enter Option Number: '))
	if opt == 1:
		number_vaults_free()
	
	elif opt == 2:
		new_vault()
	
	elif opt == 3:
		open_vault()
	
	elif opt == 4:
		return_vault()
	
	elif opt == 5:
		print('[!] Quitting....')
		os.system('exit')

	else:
		print('Wrong Option!')
