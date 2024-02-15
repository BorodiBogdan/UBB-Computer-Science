from board.board import *
import random


class ChaosPlayer:
    def __init__(self, game_board: Board):
        self.__board = game_board

    def make_random_move(self):
        while True:
            x = random.randint(0, 5)
            y = random.randint(0, 5)
            symbols = ["X", "O"]
            symbol = random.choice(symbols)

            if self.__board.get_square(x, y) == "":
                self.__board.save_to_file()
                return x, y, symbol

    def verify_stopping_move(self, i, j):
        can_be_stopped = 0

        # we verify on the column
        if j <= 2:
            can_be_stopped = 1

            for pos in range(j, j + 3):
                if self.__board.get_square(i, pos) != self.__board.get_square(i, pos + 1):
                    can_be_stopped = 0

        if can_be_stopped == 1:
            return "C"

        if i <= 2:
            can_be_stopped = 1

            for pos in range(i, i + 3):
                if self.__board.get_square(pos, j) != self.__board.get_square(pos + 1, j):
                    can_be_stopped = 0

        if can_be_stopped == 1:
            return "R"

        if i <= 2 and j <= 2:
            can_be_stopped = 1

            for pos in range(0, 3):
                if self.__board.get_square(i + pos, j + pos) != self.__board.get_square(i + pos + 1, j + pos + 1):
                    can_be_stopped = 0

        if can_be_stopped == 1:
            return "D"

        return False

    def make_stopping_move(self):
        for i in range(6):
            for j in range(6):
                if self.__board.get_square(i, j) != "":
                    stopping_move = self.verify_stopping_move(i, j)

                    chaos_character = "O"

                    if self.__board.get_square(i, j) == "O":
                        chaos_character = "X"

                    if stopping_move != False:
                        if stopping_move == "D":
                            if i - 1 > 0 and j - 1 > 0:
                                if self.__board.get_square(i - 1, j - 1) == "":
                                    return i - 1, j - 1, chaos_character
                            if i + 4 <= 5 and j + 4 <= 5:
                                if self.__board.get_square(i + 4, j + 4) == "":
                                    return i + 4, j + 4, chaos_character
                        if stopping_move == "R":
                            if i - 1 > 0:
                                if self.__board.get_square(i - 1, j) == "":
                                    return i - 1, j, chaos_character
                            if i + 4 <= 5:
                                if self.__board.get_square(i + 4, j) == "":
                                    return i + 4, j, chaos_character
                        if stopping_move == "C":
                            if j - 1 > 0:
                                if self.__board.get_square(i, j - 1) == "":
                                    return i, j - 1, chaos_character
                            if j + 4 <= 5:
                                if self.__board.get_square(i, j + 1) == "":
                                    return i, j + 4, chaos_character
        return False

    def make_move(self):
        if self.make_stopping_move() != False:
            x, y, c = self.make_stopping_move()
            self.__board.set_square(x, y, c)
        else:
            x, y, c = self.make_random_move()
            self.__board.set_square(x, y, c)

        return x, y

    def check_if_is_win(self):
        win = True

        for i in range(6):
            for j in range(6):
                if self.__board.get_square(i, j) == "":
                    win = False

        return win

