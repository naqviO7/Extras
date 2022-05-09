class BankAccount:
	""" Simple BankAccount class """
	def __init__(self,balance=0):
		self.balance=balance

	def withdraw(self,new_bal):
		self.balance = self.balance - new_bal

	def __str__(self):
		return f'Account with balance of ${self.balance}'

	def __repr__(self):
		rep='BankAccount(balance='+str(self.balance)+')'
		return rep

	def bool(self):
		if self.balance > 0:
			return True
		else:
			return False

	def __eq__(self,other):
		return (self.balance == other.balance)

	def __ne__(self,other):
		return (self.balance != other.balance)

	def __ge__(self,other):
		return (self.balance >= other.balance)

	def __le__(self,other):
		return (self.balance <= other.balance)

	def __gt__(self,other):
		return (self.balance > other.balance)

	def __lt__(self,other):
		return (self.balance < other.balance)


if __name__ == '__main__':
	account1=BankAccount(balance=100.50)
	account2=BankAccount(0)
	account3=BankAccount(100.50)

	print(account1)
	print(account2)

	print(account1.bool())
	print(account2.bool())

	account1.withdraw(200)
	print(account1.bool())

	print(account1==account2)
	print(account1!=account3)
	print(account1!=account2)
	print(account1<account2)
	print(account1>account2)
	print(account1<=account2)
	print(account1>=account2)
	print(account1<=account3)
	print(account1>=account2)
