import math
import random

def create_board():
    return [[' ' for _ in range(3)] for _ in range(3)]

def print_board(board):
    for row in board:
        print('| ' + ' | '.join(row) + ' |')
        print('----------')

def is_valid_move(board, row, col):
    return 0 <= row < 3 and 0 <= col < 3 and board[row][col] == ' '

def make_move(board, row, col, player):
    board[row][col] = player

def check_win(board, player):
    for row in board:
        if all(s == player for s in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or \
       all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def check_draw(board):
    for row in board:
        for cell in row:
            if cell == ' ':
                return False 
    return True 
def get_empty_cells(board):
    empty_cells = []
    for r in range(3):
        for c in range(3):
            if board[r][c] == ' ':
                empty_cells.append((r, c))
    return empty_cells

def get_computer_move(board):
    empty_cells = get_empty_cells(board)
    if empty_cells:
        return random.choice(empty_cells)
    return None

board = create_board()
human_player = 'X'
computer_player = 'O'
current_turn = human_player

print("Welcome to Tic-Tac-Toe!")
print(f"You are '{human_player}', and the computer is '{computer_player}'.")
print_board(board)

while True:
    if current_turn == human_player:
        while True:
            try:
                row = int(input("Enter row (0, 1, or 2): "))
                col = int(input("Enter column (0, 1, or 2): "))
                if is_valid_move(board, row, col):
                    make_move(board, row, col, human_player)
                    break
                else:
                    print("Invalid move. That cell is already taken or out of bounds. Try again.")
            except ValueError:
                print("Invalid input. Please enter a number.")
        print_board(board)
        if check_win(board, human_player):
            print("Congratulations! You win!")
            break
        elif check_draw(board):
            print("It's a draw!")
            break
        current_turn = computer_player
    else: 
        print("Computer's turn...")
        move = get_computer_move(board)
        if move:
            row, col = move
            make_move(board, row, col, computer_player)
            print_board(board)
            if check_win(board, computer_player):
                print("Computer wins!")
                break
            elif check_draw(board):
                print("It's a draw!")
                break
        current_turn = human_player

print("Game Over!")
