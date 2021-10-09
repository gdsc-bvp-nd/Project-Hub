import shutil
import random
import os
from terminaltables import AsciiTable, SingleTable

from tictactoe import TicTacToe


def show_board(game):
    table_result = SingleTable(game.get_board())
    table_result.inner_row_border = True
    print(table_result.table)
    print('\n')


def play_game(game):
    game = TicTacToe()
    print('\n')
    player1 = input('Enter your name: ')
    player2 = input('Enter your name: ')
    print('\n')
    game.set_player_names(player1, player2)

    print(
        f'{game.get_player_names()[0]} will play X and {game.get_player_names()[1]} will play O')
    print('\n')

    while game.is_running():
        show_board(game)
        game.swap_player()
        position_input = int(input(
            f'Enter the position {game.get_current_player_name()}: '))
        print('\n')
        if not game.update_board(position_input):
            print('Wrong position entered')
            print('\n')
            continue

    winner = game.get_winner()
    show_board(game)
    if winner == None:
        print('Game Tie')
        print('\n')
    elif winner == 'X':
        print(game.get_player_names()[0], 'is the winner')
        print('\n')
    elif winner == 'O':
        print(game.get_player_names()[1], 'is the winner')
        print('\n')

    


game = TicTacToe()
choice = 'Y'
while choice == 'Y' or choice == 'y':
    columns = shutil.get_terminal_size().columns
    print("TIC-TAC-TOE".center(columns))
    play_game(game)
    choice = input('Do you want to play again? (Y/N)')
    print('\n')
