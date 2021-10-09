import random


class TicTacToe:

    def set_game_state(self, start=True):
        self.game_in_progress = start

    def __init__(self):
        self.board = ['_', '_', '_',
                      '_', '_', '_',
                      '_', '_', '_']
        self.game_in_progress = True
        self.player = 'O'
        self.winner = None
        self.player_names = []

    def set_player_names(self, player1, player2):
        self.player_names = [player1, player2]
        random.shuffle(self.player_names)

    def get_player_names(self):
        return self.player_names

    def get_current_player_name(self):
        if self.player == 'X':
            return self.player_names[0]
        else:
            return self.player_names[1]

    def update_board(self, pos):
        valid_inputs = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        if pos not in valid_inputs or self.board[pos-1] != '_' or '_' not in self.board:
            return False
        self.board[pos-1] = self.player
        return True

    def get_player(self):
        return self.player

    def swap_player(self):
        if self.player == 'X':
            self.player = 'O'
        else:
            self.player = 'X'

    def check_win(self):
        win_situation = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [
            0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]]

        for wins in win_situation:
            if all(self.board[pos] == self.player for pos in wins):
                self.set_game_state(False)
                self.winner = self.get_player()
                return True

        return False

    def get_winner(self):
        return self.winner

    def check_tie(self):
        if "_" not in self.board:
            return True
        else:
            return False

    def is_running(self):
        return self.game_in_progress and self.check_win() == False and self.check_tie() == False

    def get_board(self):
        data = []
        data.append([self.board[0], self.board[1], self.board[2]])
        data.append([self.board[3], self.board[4], self.board[5]])
        data.append([self.board[6], self.board[7], self.board[8]])
        return data
