description="""
	First I have crated a list with given names in problem. 
	I have mad a funvtion called game which takes list and indexes as arguement.
	It genertaes the random indexes on the basis of user input.
	Then it deletes the players at that index.
	At the end it displays the list of players with remaining players names. 
"""
import time
import random

players=['Jan','Bill','Ti','Me','Lo','Da','Hua','Be','Ka','Po','Zo','Ca']

def game(players,indexes):
	print('Original Player List.') 
	for playr in players:
		print(playr,end=" ")
	time.sleep(3)

	print('\nGenerated Elimination Indexes.')
	for ind in indexes:
		print(ind,end=" ")
	time.sleep(3)

	print('\nEliminating Players Acording to Generated Indexes.')
	remaining=()
	for ind in indexes:
		players.pop(ind)
	time.sleep(5)

	print('Remaining Player List.') 
	for playr in players:
		print(playr,end=" ")

if __name__ == '__main__':
	tob_eliminated=int(input('Number of players to Eliminate: '))
	while tob_eliminated > 6:
		print('You cannot Eliminate More Than 6 Players')
		tob_eliminated=int(input('Number of players to Eliminate: '))
	
	indexes=[random.randint(1,tob_eliminated) for _ in range(tob_eliminated)]

game(players,indexes)
