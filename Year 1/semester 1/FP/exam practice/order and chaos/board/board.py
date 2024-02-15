from texttable import Texttable
import pickle


class Board:
    def __init__(self):
        self.__bord_table = [["" for i in range(6)] for j in range(6)]
        self.open_file()

    def __eq__(self, other):
        for i in range(6):
            for j in range(6):
                self.__bord_table[i][j] = other.get_square(i, j)

    def open_file(self):
        with open("data.pkl", "rb") as file:
            self.__bord_table = pickle.load(file)
            file.close()

    def save_to_file(self):
        with open("data.pkl", "wb") as file:
            pickle.dump(self.__bord_table, file)
            file.close()

    @property
    def get_board(self):
        return self.__bord_table

    def get_square(self, x, y):
        return self.__bord_table[x][y]

    def set_square(self, x: int, y: int, symbol: str):
        if self.__bord_table[x][y] == "X" or self.__bord_table[x][y] == "Y":
            raise ValueError("Bag pl")

        self.__bord_table[x][y] = symbol
        self.save_to_file()

    def set_square_for_clear(self, x: int, y: int):
        self.__bord_table[x][y] = ""

    def to_str(self):
        printed_board = Texttable()

        printed_board.header(['/', 0, 1, 2, 3, 4, 5])

        for i in range(6):
            added_row = [i]
            for j in range(6):
                added_row.append(self.get_square(i, j))

            printed_board.add_row(added_row)

        return printed_board.draw()

    def __str__(self):
        printed_board = Texttable()

        printed_board.header(['/', 0, 1, 2, 3, 4, 5])

        for i in range(6):
            added_row = [i]
            for j in range(6):
                added_row.append(self.get_square(i, j))

            printed_board.add_row(added_row)

        return printed_board.draw()
