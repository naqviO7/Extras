from random import randint

# Class stack (for each column)
class Stack:
    def __init__(self):
        self._list = []
    
    def __len__(self):
        return len(self._list)    
    
    def push(self, element):
        if len(self._list) <= 6:
            self._list.append(element)
        else:
            return
    
    def peek(self):
        return self._list[-1]


#player class
class Player: 
    def __init__(self,name,symbol):
        self.name=name
        self.symbol=symbol

    def get_name(self):
        return self.name

    def get_symbol(self):
        return self.symbol


#game class
class Game:
    def __init__(self,n,height,width):
        self.n=n
        self.height=height
        self.width=width

    def add_player(self,name,symbol):
        self.name=name
        self.symbol=symbol

#board class
class Board:
    def height(self):
        return self.height

    def width(self):
        return self.width

    def can_play(self,col_index):
        self.col_index=col_index
        for i in range(0,4):
            for j in range(0,3):
                if (board[j][i]==board[j+1][i+1]==\
                    board[j+2][i+2]==board[j+3][i+3]==S or
                    board[j+3][i]==board[j+2][i+1]==\
                    board[j+1][i+2]==board[j][i+3]==S):
                    return True
        return False

    def max_run(self,row_index,col_index):
        self.max_run=max_run
        self.rows_index=rows_index
        self.col_index=col_index
        
        for i in range(0,len(rows)):
            board.append([' '] * 7)
        
        return max_run


# Initialize board (empty)
def initBoard():
    # empty board
    rows = ['a','b','c','d','e','f']
    board = []
    for i in range(0,len(rows)):
        board.append([' '] * 7)
    
    return board


# Initialize Stacks (empty
def initStacks():
    S = [ Stack(), Stack(), Stack(), 
         Stack(), Stack(), Stack(), Stack() ]
    return S


# print board
def printBoard(board):
    rows = ['1','2','3','4','5','6']
    top = '    1   2   3   4   5   6   7   '
    row = [[n] for n in range(0,7)]
    row[0][0] = '6 | '
    row[1][0] = '5 | '
    row[2][0] = '4 | '
    row[3][0] = '3 | '
    row[4][0] = '2 | '
    row[5][0] = '1 | '
    print('')
    print('  ' + '-'*(len(top)-3))
    for j in range(0,len(rows)):
        for i in range(1,8):
            row[j][0] = row[j][0] + str(board[j][i-1]) + ' | '
        print(row[j][0])
        print('  ' + '-'*((len(row[j][0])-3)))
    print(top)
    print('')
   

# Move
def move(piece, board, Stacks, computer):
    Set0 = {'1','2','3','4','5','6','7'}
    if piece == computer:
        pos = randint(1,7)
        if len(Stacks[pos-1]) < 6:
            Stacks[pos-1].push(piece)
            board[6-len(Stacks[pos-1])][pos-1] = \
                Stacks[pos-1].peek()
        else:
            move(piece, board, Stacks, computer)
    else:
        pos = str(input('Your move: '))
        if (pos in Set0) == False:
            print('Input must be integer between 1 and 7')
            move(piece, board, Stacks, computer)
        else: 
            pos = int(pos)
            if len(Stacks[pos-1]) < 6:
                Stacks[pos-1].push(piece)
                board[6-len(Stacks[pos-1])][pos-1] = \
                    Stacks[pos-1].peek()
            else:
                print('Column full, try again...')
                move(piece, board, Stacks, computer)
    return board, Stacks


# Check wins
def checkWin(S,board):
    game = False   
    # Horizontal checker
    for j in range(0,6):
        for i in range(3,7):
            if (board[j][i]==board[j][i-1]==\
                board[j][i-2]==board[j][i-3]==S):
                    game = True
            else:
                continue   
    # Vertical checker
    for i in range(0,7):
        for j in range(3,6):
            if (board[j][i]==board[j-1][i]==\
                board[j-2][i]==board[j-3][i]==S):
                    game = True
            else:
                continue
    # Diagonal checker
    for i in range(0,4):
        for j in range(0,3):
            if (board[j][i]==board[j+1][i+1]==\
                board[j+2][i+2]==board[j+3][i+3]==S or
                board[j+3][i]==board[j+2][i+1]==\
                board[j+1][i+2]==board[j][i+3]==S):
                    game = True
            else:
                continue
    if game == True:
        print(S + ' wins!')
    return game


# Main program
def main():
    # Prompt player input
    player=str(input('Enter Name: '))
    player1 = str( input('Choose X or O: ') )
    if player1 != 'X' and player1 != 'O':
        player1 = str( input('Choose X or O: ') )
    
    if player1 == 'X':
        computer1 = 'O'
    else:
        computer1 = 'X'
        
    # Print board
    board = initBoard()
    Stacks = initStacks()
    printBoard(board)
    print('To play: enter an integer between 1 to 7 ' + \
          'corresponding to each column in the board. ' + \
          'Whoever stacks 4 pieces next to each other, ' + \
          'either horizontally, vertically or diagonally wins.')
    
    game = False
    
    while game == False:
        # X player
        board, Stacks = move('X',board,Stacks,computer1)
        printBoard(board)
        game = checkWin('X',board)
        if game == True:
            break
        
        # O player
        board, Stacks = move('O',board,Stacks,computer1)
        printBoard(board)
        game = checkWin('O',board)
        
        if game == True:
            break
    
    print('Good game.')

    
#calling functions    
if __name__ == '__main__':
    main()
