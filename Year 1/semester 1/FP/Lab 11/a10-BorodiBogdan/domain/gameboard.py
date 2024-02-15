from texttable import Texttable
WIDTH = 6
HEIGHT = 6
FREE_SPACE = " "


class GameBoard:
    def __init__(self):
        self.__board = [[FREE_SPACE for _ in range(WIDTH)] for _ in range(HEIGHT)]

    def get_square(self, x_coordinate, y_coordinate):
        return self.__board[x_coordinate][y_coordinate]

    @property
    def board(self):
        return self.__board

    def __eq__(self, other):
        for row in range(HEIGHT):
            for column in range(WIDTH):
                self.__board[row][column] = other[row][column]

    def __str__(self):
        printed_board = Texttable()
        header = ['/', '0', '1', '2', '3', '4', '5']
        printed_board.header(header)

        for index in range(HEIGHT):
            row = [index]
            for index2 in range(WIDTH):
                row.append(self.__board[index][index2])

            printed_board.add_row(row)

        return printed_board.draw()


"""
        game_board_to_string = ""
        for row in range(HEIGHT):
            for column in range(WIDTH):
                game_board_to_string += str(self.__board[row][column]) + " "
            game_board_to_string += "\n"
        return game_board_to_string
"""
